#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "ChessBoard.hpp"
#include "QPixmapManager.h"
#include <QTimer>
struct LineConfig {
    int offset = 8;      // ¾àÀëÆå×Ó±ßÔµµÄÆ«ÒÆÁ¿
    int length = 12;     // ÕÛÏßµÄ³¤¶È
    int penWidth = 3;    // »­±Ê¿í¶È
    QColor color = Qt::red;  // ÕÛÏßÑÕÉ«
    bool antialiasing = true; // ¿¹¾â³Ý

    LineConfig() = default;
    LineConfig(const QColor& c, int off = 8, int len = 12, int width = 3)
        : offset(off), length(len), penWidth(width), color(c) {
    }
};
class Dialog : public QDialog
{
    Q_OBJECT  // Required for signals/slots

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void onBtnSwapSide();  // Slot for button click
    void onBtnNewGame();
    void onBtnShowStatic();
    void onBtnShowSelected();
    void onDrawTimer();
protected:
    virtual void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
private:
    int M_DIALOG_MAX_WIDTH;
    int M_DIALOG_MAX_HEIGHT;
    int M_BOARD_MAX_WIDTH;
    int M_BOARD_MAX_HEIGHT;
    int M_CONTROL_MAX_WIDTH;
    int M_CONTROL_MAX_HEIGHT;

    QLabel *m_label;
    QFrame* m_btnsWidget;
    QPushButton *m_button;
    QPushButton* m_newGameBtn;
    QPushButton* m_aboutBtn;
    QPushButton* m_showStaticBtn;
    QPushButton* m_showSelectedBtn;
    QVBoxLayout *m_layout;
    ChessBoard m_board;
    QPixmapManager m_imgManager;

    QTimer * m_drawTimer;
    bool m_bDrawSelected;
    QPixmap m_staticMemImg;   // ÆåÅÌ±³¾°Í¼
    QPixmap m_selectedMemImg;


    bool m_bChessSelected;
	ChessGrid_T m_selectedGrid;
	ChessGrid_T m_targetGrid;

	ChessGrid_T PointToGrid(const QPoint& pt);
    void updateStaticMemImage();
    void updateSelectedMemImage();
    void drawSelectionMark(QPixmap& pixmap,
        const QPoint& topLeft,
        int width,
        const LineConfig& config);
};

#endif // DIALOG_H