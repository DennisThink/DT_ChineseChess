#include "dialog.h"
#include <qevent.h>
#include <QPainter>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    {
        M_DIALOG_MAX_WIDTH=800;
        M_DIALOG_MAX_HEIGHT=640;
        M_BOARD_MAX_WIDTH=558;
        M_BOARD_MAX_HEIGHT=620;
        M_CONTROL_MAX_HEIGHT = M_DIALOG_MAX_HEIGHT;
        M_CONTROL_MAX_WIDTH = M_DIALOG_MAX_WIDTH - M_BOARD_MAX_WIDTH;
        m_bDrawSelected = false;
        m_drawTimer = new QTimer(this);
        connect(m_drawTimer, &QTimer::timeout, this, &Dialog::onDrawTimer);
        m_drawTimer->start(200);
        m_bChessSelected = false;
    }
    // Set window title
    setWindowTitle("Simple Qt Dialog");
    
    // Create widgets
    m_label = new QLabel("Hello, Qt!");
    m_label->setAlignment(Qt::AlignCenter);
    
    m_button = new QPushButton("SwapSide");
    m_newGameBtn = new QPushButton("NewGame");
    m_showSelectedBtn = new QPushButton("Selected");
    m_showStaticBtn = new QPushButton("ShowStatic");
    // Create layout and add widgets
    m_btnsWidget = new QFrame(this);
    m_btnsWidget->setFrameStyle(QFrame::Box | QFrame::Raised);
    m_btnsWidget->setLineWidth(2);
    m_layout = new QVBoxLayout(m_btnsWidget);
    m_layout->addWidget(m_label);
    m_layout->addWidget(m_button);
    m_layout->addWidget(m_newGameBtn);
    m_layout->addWidget(m_showSelectedBtn);
    m_layout->addWidget(m_showStaticBtn);
    
    // Connect button click to slot
    connect(m_button, &QPushButton::clicked, 
            this, &Dialog::onBtnSwapSide);

    connect(m_newGameBtn, &QPushButton::clicked,
        this, &Dialog::onBtnNewGame);

    connect(m_showSelectedBtn, &QPushButton::clicked,
        this, &Dialog::onBtnShowSelected);

    connect(m_showStaticBtn, &QPushButton::clicked,
        this, &Dialog::onBtnShowStatic);
    
    // Set dialog size
    resize(M_DIALOG_MAX_WIDTH, M_DIALOG_MAX_HEIGHT);
    m_btnsWidget->move(M_BOARD_MAX_WIDTH, 0);
    m_btnsWidget->setFixedSize(M_CONTROL_MAX_WIDTH, M_CONTROL_MAX_HEIGHT);
}
void Dialog::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    if (m_bDrawSelected)
    {
        painter.drawPixmap(0, 0, m_selectedMemImg);
    }
    else
    {
        painter.drawPixmap(0, 0, m_staticMemImg);
    }
}


Dialog::~Dialog()
{
    // Qt handles deletion of child widgets automatically
}

void Dialog::onBtnSwapSide()
{
    // Change label text when button is clicked
    m_label->setText("SwapSide");
    m_board.SwapSide();
    updateStaticMemImage();
	updateSelectedMemImage();
    update();
    // Optional: Show a message box
    // QMessageBox::information(this, "Info", "Button was clicked!");
}

void Dialog::onBtnNewGame()
{
    m_label->setText("NewGame");
}
void Dialog::onBtnShowStatic()
{
    m_label->setText("ShowStatic");
    updateStaticMemImage();
    m_bDrawSelected = false;
    update();
}
void Dialog::onBtnShowSelected()
{
    m_label->setText("ShowSelected");
    updateSelectedMemImage();
    m_bDrawSelected = true;
    update();
}
ChessGrid_T Dialog::PointToGrid(const QPoint& pt)
{
    ChessGrid_T result;
    int CHESS_CELL_WIDTH = 58;
    int CHESS_START_X = 20;
    int CHESS_START_Y = 20;
    result._gridX = (pt.x() - CHESS_START_X) / CHESS_CELL_WIDTH;
    result._gridY = (pt.y() - CHESS_START_Y) / CHESS_CELL_WIDTH;
	return result;
}
void Dialog::updateStaticMemImage()
{
    QString imagePath("main.gif");
    // 1. 加载原始图片
    QPixmap original(imagePath);

    if (original.isNull()) {
        qDebug() << "Failed to load image:" << imagePath;
       // return QPixmap();
        return;
    }

    if (m_staticMemImg.isNull()) {
        m_staticMemImg = QPixmap(M_BOARD_MAX_WIDTH,M_BOARD_MAX_HEIGHT);
    }
   
    m_staticMemImg.fill(Qt::transparent);  // 透明背景
    // 3. 创建 QPainter 绘制到 result
    QPainter painter(&m_staticMemImg);
    // 6. 绘制到 result
    painter.drawPixmap(0, 0, original);
    {
        int CHESS_CELL_WIDTH = 58;
        int CHESS_START_X = 20;
        int CHESS_START_Y = 20;

        int chessX = CHESS_START_X;
        int chessY = CHESS_START_Y;

        //m_board.SetBoardToStartState();
        int maxX = m_board.GetMaxX();
        int maxY = m_board.GetMaxY();
        const QPixmap& maskImage = m_imgManager.GetChessManMaskImage();
        auto& board = m_board.GetBoardData();
        for (int x = 0; x < maxX; x++)
        {
            for (int y = 0; y < maxY; y++)
            {
                const ChessManBoardElem& elem = board._board[x][y];
                if (elem._color != ChessColor::NONE_SIDE && elem._manType != ChessMan_T::NONE_MAN)
                {
                    const QPixmap& chessManImg = m_imgManager.GetChessManImage(elem._color, elem._manType);
                    chessX = CHESS_START_X + CHESS_CELL_WIDTH * x;
                    chessY = CHESS_START_Y + CHESS_CELL_WIDTH * y;
                    painter.drawPixmap(chessX, chessY, chessManImg);
                    //chessManImg.Draw(workDC.GetSafeHdc(), chessX, chessY, CHESS_CELL_WIDTH, CHESS_CELL_WIDTH, 0, 0, CHESS_CELL_WIDTH, CHESS_CELL_WIDTH);
                }
            }
        }
    }
}
void Dialog::updateSelectedMemImage()
{
    if (m_selectedMemImg.isNull()) {
        m_selectedMemImg = QPixmap(M_BOARD_MAX_WIDTH, M_BOARD_MAX_HEIGHT);
    }
    {
        QPainter painter(&m_selectedMemImg);
        // 6. 绘制到 result
        painter.drawPixmap(0, 0, m_staticMemImg);
       
    }
    if (m_board.IsGoodSelectedGrid(m_selectedGrid))
    {
        QPoint center;
        int CHESS_CELL_WIDTH = 58;
        int CHESS_START_X = 20;
        int CHESS_START_Y = 20;
        center.setX(CHESS_START_X + m_selectedGrid._gridX * CHESS_CELL_WIDTH);
        center.setY(CHESS_START_Y + m_selectedGrid._gridY * CHESS_CELL_WIDTH);
        LineConfig config;
        drawSelectionMark(m_selectedMemImg, center, CHESS_CELL_WIDTH, config);
    }

}

void  Dialog::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPoint pt = event->pos();
        ChessGrid_T curGrid = PointToGrid(pt);
       
        if (m_board.IsGridInBoard(curGrid))
        {
            if (m_bChessSelected)
            {
                m_targetGrid = curGrid;

                ChessMove_T moveAct;
                moveAct._chessMan = m_board.GetGridChess(m_selectedGrid);
                moveAct._fromGrid = m_selectedGrid;
                moveAct._toGrid = m_targetGrid;
                if (m_board.OnMove(moveAct))
                {
                    m_bChessSelected = false;
                    m_selectedGrid.Reset();
                    m_targetGrid.Reset();
                    updateStaticMemImage();
                    updateSelectedMemImage();
                    update();
                }
                else
                {
                    m_targetGrid.Reset();
                    const ChessManBoardElem& chessMan = m_board.GetGridChess(curGrid);
                    if (chessMan._color != ChessColor::NONE_SIDE && chessMan._manType != ChessMan_T::NONE_MAN)
                    {
                        m_selectedGrid = curGrid;
                        m_bChessSelected = true;
                        updateStaticMemImage();
                        updateSelectedMemImage();
                    }
                }
            }
            else
            {
                const ChessManBoardElem& chessMan = m_board.GetGridChess(curGrid);
                if (chessMan._color != ChessColor::NONE_SIDE && chessMan._manType != ChessMan_T::NONE_MAN)
                {
                    m_selectedGrid = curGrid;
                    m_bChessSelected = true;
                    updateStaticMemImage();
                    updateSelectedMemImage();
                }
            }
        }
    }
    if (event->button() == Qt::RightButton)
    {
        m_bChessSelected = false;
        m_bDrawSelected = false;
        updateSelectedMemImage();
        update();
    }
}
void  Dialog::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
       
    }
}

void Dialog::drawSelectionMark(QPixmap& pixmap,
    const QPoint& topLeft,
    int width,
    const LineConfig& config)
{
    if (pixmap.isNull()) {
        qWarning() << "ChessMarker::drawSelectionMark: pixmap is null";
        return;
    }

    QPainter painter(&pixmap);

    if (config.antialiasing) {
        painter.setRenderHint(QPainter::Antialiasing);
    }

    painter.setPen(QPen(config.color, config.penWidth));
    painter.setBrush(Qt::NoBrush);

    // 计算四个角的位置
    int offset = config.offset;
    int length = config.length;

    // 左上角
    QPoint topLeftCorner(topLeft.x() + offset, topLeft.y() + offset);
    // 右上角
    QPoint topRightCorner(topLeft.x() + width - offset, topLeft.y() + offset);
    // 左下角
    QPoint bottomLeftCorner(topLeft.x() + offset, topLeft.y() + width - offset);
    // 右下角
    QPoint bottomRightCorner(topLeft.x() + width - offset, topLeft.y() + width - offset);

    // 绘制左上角 L 形
    painter.drawLine(topLeftCorner, topLeftCorner + QPoint(length, 0));
    painter.drawLine(topLeftCorner, topLeftCorner + QPoint(0, length));

    // 绘制右上角 L 形
    painter.drawLine(topRightCorner, topRightCorner + QPoint(-length, 0));
    painter.drawLine(topRightCorner, topRightCorner + QPoint(0, length));

    // 绘制左下角 L 形
    painter.drawLine(bottomLeftCorner, bottomLeftCorner + QPoint(length, 0));
    painter.drawLine(bottomLeftCorner, bottomLeftCorner + QPoint(0, -length));

    // 绘制右下角 L 形
    painter.drawLine(bottomRightCorner, bottomRightCorner + QPoint(-length, 0));
    painter.drawLine(bottomRightCorner, bottomRightCorner + QPoint(0, -length));

    /*
    {
        painter.setPen(QPen(Qt::blue, 1));
        painter.drawRect(topLeft.x(), topLeft.y(), width, width);

        // 2. 在四个角点画红点
        painter.setPen(QPen(Qt::red, 3));
        painter.drawPoint(topLeftCorner);
        painter.drawPoint(topRightCorner);
        painter.drawPoint(bottomLeftCorner);
        painter.drawPoint(bottomRightCorner);

        // 3. 在中心画绿点
        QPoint center(topLeft.x() + width / 2, topLeft.y() + width / 2);
        painter.setPen(QPen(Qt::green, 5));
        painter.drawPoint(center);
    }*/
}

void Dialog::onDrawTimer()
{
    m_bDrawSelected = !m_bDrawSelected;
    update();
}