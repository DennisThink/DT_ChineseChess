// ChessDialog.cpp
#include "ChessDialog.h"
#include "ID_def.h"
BEGIN_MESSAGE_MAP(CChessDialog, CDialog)
    ON_WM_PAINT()
    ON_WM_TIMER()
    ON_COMMAND(MENU_ID_NEW_GAME, &CChessDialog::OnNewGame)
    ON_COMMAND(MENU_ID_CHINESE_CHESS, &CChessDialog::OnChineseChess)
    ON_COMMAND(MENU_ID_ABOUT, &CChessDialog::OnAbout)
    ON_COMMAND(MENU_ID_DRAW_STATIC,&CChessDialog::OnTestStaticImage)
    ON_COMMAND(MENU_ID_DRAW_SELECTED, &CChessDialog::OnTestSelectedImage)
    ON_MESSAGE(WM_USER_UPDATE_INFO, &CChessDialog::OnUpdateInfo)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

CChessDialog::CChessDialog(CWnd* pParent)
    : CDialog(CChessDialog::IDD, pParent) 
{
    m_bDrawStaticBoard = false;
    m_selectedX = 0;
    m_selectedY = 0;
}


BOOL CChessDialog::OnInitDialog() {
    BOOL bResult = CDialog::OnInitDialog();
    if (bResult)
    {

    }
    else
    {
        MessageBox(_T("Failed"));
    }
    // 设置窗口标题和大小
    SetWindowText(_T("象棋游戏"));
    SetWindowPos(nullptr, 0, 0, 800, 700, SWP_NOMOVE | SWP_NOZORDER);
    
    // 创建菜单栏
    CreateMenuBar();
    
    // 创建棋盘控件
    /*CRect rect(50, 50, 750, 600);
    m_boardCtrl.Create(this, rect, 101);
    
    // 创建信息栏
    CRect infoRect(50, 610, 750, 640);
    m_infoText.Create(_T(""), WS_CHILD | WS_VISIBLE | SS_CENTER, 
                      infoRect, this, 102);
    
    // 初始化中国象棋引擎
    m_engine = std::make_unique<ChineseChessEngine>();
    m_boardCtrl.SetEngine(m_engine.get());*/
    
    UpdateInfo();
    DrawMenuBar();


    return TRUE;
}

BOOL CChessDialog::CreateDialogWindow()
{
    // 计算窗口大小
    RECT rect = { 100, 100, 900, 800 };


    // 注册窗口类（只注册一次）
    static BOOL bRegistered = FALSE;
    if (!bRegistered)
    {
        WNDCLASS wc = {};
        wc.lpfnWndProc = AfxWndProc;  // MFC 标准窗口过程
        wc.hInstance = AfxGetInstanceHandle();
        wc.lpszClassName = _T("ChessDialogClass");
        wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wc.style |= CS_DBLCLKS;
        if (!AfxRegisterClass(&wc))
        {
            TRACE(_T("AfxRegisterClass failed\n"));
            return FALSE;
        }

        bRegistered = TRUE;
    }


    // 创建窗口
    if (!CreateEx(0, _T("ChessDialogClass"), _T("Chess Game"),
        WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME| WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
        rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
        nullptr, nullptr))
    {
        return FALSE;
    }

    return TRUE;
}

INT_PTR CChessDialog::DoModal()
{
    // 关键步骤1：创建窗口（但不显示）
    if (!CreateDialogWindow())
    {
        TRACE(_T("Failed to create dialog window\n"));
        return -1;
    }

    // 关键步骤2：设置模态状态
    CWnd* pParentWnd = GetParent();
    if (pParentWnd)
        pParentWnd->EnableWindow(FALSE);  // 禁用父窗口

    CreateMenuBar();
    DrawMenuBar();
    // 关键步骤3：显示窗口
    ShowWindow(SW_SHOW);
    UpdateWindow();
    UpdateStaticBitmap();
    UpdateSelectedBitmap();
    SetTimer(TIMER_RENDER, RENDER_INTERVAL, nullptr);
    // 关键步骤4：进入模态消息循环
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        // 检查是否应该退出模态循环
        if (msg.message == WM_QUIT)
        {
            PostQuitMessage((int)msg.wParam);
            break;
        }

        // 让对话框处理消息
        if (!IsDialogMessage(&msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // 如果窗口已销毁，退出循环
        if (!::IsWindow(m_hWnd))
            break;
    }

    // 关键步骤5：清理
    if (pParentWnd)
        pParentWnd->EnableWindow(TRUE);

    // 销毁窗口
    if (m_hWnd)
        DestroyWindow();

    return IDOK;
}

void CChessDialog::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    int CHESS_CELL_WIDTH = 58;
    int CHESS_START_X = 20;
    int CHESS_START_Y = 20;
    int gridX = (point.x - CHESS_START_X) / CHESS_CELL_WIDTH;
    int gridY = (point.y - CHESS_START_Y) / CHESS_CELL_WIDTH;
    if ((0 <= gridX && gridX < m_board.GetMaxX()) &&
        (0 <= gridY && gridY < m_board.GetMaxY()))
    {
        /*ChessManBoardElem selectedElem = m_board._board[gridX][gridY];
        if (selectedElem._color != ChessColor::NONE_SIDE && selectedElem._manType != ChessMan_T::NONE_MAN)
        {
            m_selectedX = gridX;
            m_selectedY = gridY;
            UpdateSelectedBitmap();
        }*/
    }
}
void CChessDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
    int CHESS_CELL_WIDTH = 58;
    int CHESS_START_X = 20;
    int CHESS_START_Y = 20;
    int gridX = (point.x - CHESS_START_X) / CHESS_CELL_WIDTH;
    int gridY = (point.y - CHESS_START_Y) / CHESS_CELL_WIDTH;
    if ((0 <= gridX && gridX < m_board.GetMaxX())&&
        (0 <= gridY && gridY < m_board.GetMaxY()))
    {
        /*ChessManBoardElem selectedElem = m_board._board[gridX][gridY];
        if (selectedElem._color != ChessColor::NONE_SIDE && selectedElem._manType != ChessMan_T::NONE_MAN)
        {
            m_selectedX = gridX;
            m_selectedY = gridY;
            UpdateSelectedBitmap();
        }*/
    }
}
void CChessDialog::CreateMenuBar() {
    // 确保菜单句柄有效
    if (m_menu.GetSafeHmenu())
    {
       
    }
    else
    {
        m_menu.CreateMenu();
    }
    
    // 游戏菜单
    {
        CMenu* pGameMenu = new CMenu();
        pGameMenu->CreatePopupMenu();
        pGameMenu->AppendMenu(MF_STRING, MENU_ID_NEW_GAME, _T("新游戏(&N)"));
        pGameMenu->AppendMenu(MF_STRING, MENU_ID_CHINESE_CHESS, _T("中国象棋(&C)"));
        pGameMenu->AppendMenu(MF_STRING, MENU_ID_ABOUT, _T("关于(&A)"));
        pGameMenu->AppendMenu(MF_SEPARATOR);
        pGameMenu->AppendMenu(MF_STRING, IDCANCEL, _T("退出(&X)"));
        m_menu.AppendMenu(MF_POPUP, (UINT_PTR)(pGameMenu->Detach()), _T("游戏(&G)"));
    }
    {
        CMenu* pTestMenu = new CMenu();
        pTestMenu->CreatePopupMenu();
        pTestMenu->AppendMenu(MF_STRING, MENU_ID_DRAW_STATIC, _T("未选择棋子"));
        pTestMenu->AppendMenu(MF_STRING, MENU_ID_DRAW_SELECTED, _T("已选择棋子"));
        m_menu.AppendMenu(MF_POPUP, (UINT_PTR)(pTestMenu->Detach()), _T("棋盘测试"));
    }
    
    {
        CMenu* pTestMenu = new CMenu();
        pTestMenu->CreatePopupMenu();
        pTestMenu->AppendMenu(MF_STRING, MENU_ID_NEXT_STEP, _T("下一步"));
        pTestMenu->AppendMenu(MF_STRING, MENU_ID_PREV_STEP, _T("上一步"));
        m_menu.AppendMenu(MF_POPUP, (UINT_PTR)(pTestMenu->Detach()), _T("打谱"));
    }
    SetMenu(&m_menu);
    DrawMenuBar();
}

void CChessDialog::DrawPaintDC(CPaintDC* pDC)
{
    if (nullptr != pDC)
    {
        if (m_bDrawStaticBoard)
        {
            // 创建内存 DC
            CDC memDC;
            memDC.CreateCompatibleDC(pDC);

            // 将位图选入内存 DC
            CBitmap* pOldBitmap = memDC.SelectObject(&m_staticBitmap);

            // 复制到屏幕（位块传输）
            pDC->BitBlt(m_boardRect.left, m_boardRect.top, m_boardRect.Width(), m_boardRect.Height(), &memDC, 0, 0, SRCCOPY);

            // 恢复原状
            memDC.SelectObject(pOldBitmap);
        }
        else
        {
            // 创建内存 DC
            CDC memDC;
            memDC.CreateCompatibleDC(pDC);

            // 将位图选入内存 DC
            CBitmap* pOldBitmap = memDC.SelectObject(&m_selectedBitmap);

            // 复制到屏幕（位块传输）
            pDC->BitBlt(m_boardRect.left, m_boardRect.top, m_boardRect.Width(), m_boardRect.Height(), &memDC, 0, 0, SRCCOPY);

            // 恢复原状
            memDC.SelectObject(pOldBitmap);
            //pDC->BitBlt(0, 0, m_boardRect.Width(), m_boardRect.Height(), &m_selectedDC, 0, 0, SRCCOPY);
        }
    }
}
void CChessDialog::OnNewGame() {
    /*if (m_engine) {
        m_engine->reset();
        m_boardCtrl.Refresh();
        UpdateInfo();
    }*/
    MessageBox(_T("新游戏"));
}

void CChessDialog::OnChineseChess() {
    //m_engine = std::make_unique<ChineseChessEngine>();
    //m_boardCtrl.SetEngine(m_engine.get());
    //m_boardCtrl.Refresh();
    UpdateInfo();
    MessageBox(_T("中国象棋"));
}

void CChessDialog::OnAbout() {
    AfxMessageBox(_T("象棋游戏\n使用 MFC Dialog 实现\n支持中国象棋和国际象棋"),
                  MB_OK | MB_ICONINFORMATION);
}

LRESULT CChessDialog::OnUpdateInfo(WPARAM, LPARAM) {
    UpdateInfo();
    return 0;
}
void CChessDialog::OnTestStaticImage()
{
   
    UpdateStaticBitmap();
    MessageBox(_T("OnTestStaticImage"));
    m_bDrawStaticBoard = true;
    Invalidate();
    UpdateWindow();
}
void CChessDialog::OnTestSelectedImage()
{
    UpdateSelectedBitmap();
    MessageBox(_T("OnTestSelectedImage"));
    m_bDrawStaticBoard = false;
    Invalidate(TRUE);
}
void CChessDialog::UpdateInfo() {
    /*if (!m_engine) return;
    
    CString info;
    info.Format(_T("当前: %s | %s"),
                m_engine->getBoardDescription().c_str(),
                m_engine->isGameOver() ? _T("游戏结束") : _T("对局中"));
    m_infoText.SetWindowText(info);*/
}

void CChessDialog::UpdateStaticBitmap()
{
    if (m_staticBitmap.GetSafeHandle())
    {
        m_staticBitmap.DeleteObject();  // 释放原资源
    }
    CClientDC targetDC(this);  // 获取窗口的设备信息
    const CImage& boardImage = m_imageManager.GetBoardImage();
    int width = boardImage.GetWidth();
    int height = boardImage.GetHeight();
    if (width > 0 && height > 0)
    {
        m_boardRect.left = 0;
        m_boardRect.top = 0;
        m_boardRect.right = width;
        m_boardRect.bottom = height;
    }

    // 创建兼容位图
    if (!m_staticBitmap.CreateCompatibleBitmap(&targetDC, width, height))
    {
        return;
    }

    // 创建工作 DC
    CDC workDC;
    if (!workDC.CreateCompatibleDC(&targetDC))
    {
        return;
    }
    // 将位图选入工作 DC
    CBitmap* pOldBitmap = workDC.SelectObject(&m_staticBitmap);
    workDC.FillSolidRect(0, 0, width, height, RGB(255, 255, 255));  // 白色背景
    // 在内存 DC 上绘制 CImage
    boardImage.Draw(workDC.GetSafeHdc(), 0, 0, width, height, 0, 0, width, height);
    {
        //Draw staticMemoryImg
        {
            int CHESS_CELL_WIDTH = 58;
            int CHESS_START_X = 20;
            int CHESS_START_Y = 20;

            int chessX = CHESS_START_X;
            int chessY = CHESS_START_Y;
          
            //m_board.SetBoardToStartState();
            int maxX = m_board.GetMaxX();
            int maxY = m_board.GetMaxY();
            const CImage& maskImage = m_imageManager.GetChessManMaskImage();
			const ChineseBoardData_T& boardData = m_board.GetBoardData();
            for (int x = 0; x < maxX; x++)
            {
                for (int y = 0; y < maxY; y++)
                {
                    ChessManBoardElem elem = boardData._board[x][y];
                    if (elem._color != ChessColor::NONE_SIDE && elem._manType != ChessMan_T::NONE_MAN)
                    {
                        const CImage& chessManImg = m_imageManager.GetChessManImage(elem._color, elem._manType);
                        chessX = CHESS_START_X + CHESS_CELL_WIDTH * x;
                        chessY = CHESS_START_Y + CHESS_CELL_WIDTH * y;
                        HDC hPieceDC = chessManImg.GetDC();
                        HDC hMaskDC = maskImage.GetDC();
                        ::BitBlt(workDC.GetSafeHdc(), chessX, chessY, width, height,
                            hMaskDC, 0, 0, SRCAND);
                        ::BitBlt(workDC.GetSafeHdc(), chessX, chessY, width, height,
                            hPieceDC, 0, 0, SRCPAINT);
                        chessManImg.ReleaseDC();
                        maskImage.ReleaseDC();
                        //chessManImg.Draw(workDC.GetSafeHdc(), chessX, chessY, CHESS_CELL_WIDTH, CHESS_CELL_WIDTH, 0, 0, CHESS_CELL_WIDTH, CHESS_CELL_WIDTH);
                    }
                }
            }
        }
    }
    // 恢复原状
    workDC.SelectObject(pOldBitmap);
}

void CChessDialog::drawCornerMarks(CDC* pDC, int x, int y, int pieceSize, int cornerLen, int lineWidth, COLORREF color)
{
    int oldBkMode = pDC->SetBkMode(TRANSPARENT);
    CPen pen(PS_SOLID, lineWidth, color);
    CPen* pOldPen = pDC->SelectObject(&pen);

    int smallCorner = cornerLen / 2;

    // 使用 Polyline 可以更高效地绘制多条线段
    POINT leftTop[2] = { {x, y}, {x + smallCorner, y} };
    POINT leftTop2[2] = { {x, y}, {x, y + smallCorner} };
    POINT rightTop[2] = { {x + pieceSize, y}, {x + pieceSize - smallCorner, y} };
    POINT rightTop2[2] = { {x + pieceSize, y}, {x + pieceSize, y + smallCorner} };
    POINT leftBottom[2] = { {x, y + pieceSize}, {x + smallCorner, y + pieceSize} };
    POINT leftBottom2[2] = { {x, y + pieceSize}, {x, y + pieceSize - smallCorner} };
    POINT rightBottom[2] = { {x + pieceSize, y + pieceSize}, {x + pieceSize - smallCorner, y + pieceSize} };
    POINT rightBottom2[2] = { {x + pieceSize, y + pieceSize}, {x + pieceSize, y + pieceSize - smallCorner} };

    pDC->Polyline(leftTop, 2);
    pDC->Polyline(leftTop2, 2);
    pDC->Polyline(rightTop, 2);
    pDC->Polyline(rightTop2, 2);
    pDC->Polyline(leftBottom, 2);
    pDC->Polyline(leftBottom2, 2);
    pDC->Polyline(rightBottom, 2);
    pDC->Polyline(rightBottom2, 2);

    // 恢复原来的GDI对象和状态
    pDC->SelectObject(pOldPen);
    pDC->SetBkMode(oldBkMode);
}
void CChessDialog::UpdateSelectedBitmap()
{
    CPaintDC dc(this);
    if (m_selectedBitmap.GetSafeHandle())
    {
        m_selectedBitmap.DeleteObject();  // 释放原资源
    }
    const CImage& boardImage = m_imageManager.GetBoardImage();
    int width = boardImage.GetWidth();
    int height = boardImage.GetHeight();
    if (width > 0 && height > 0)
    {
        m_boardRect.left = 0;
        m_boardRect.top = 0;
        m_boardRect.right = width;
        m_boardRect.bottom = height;
    }

    // 创建兼容位图
    if (!m_selectedBitmap.CreateCompatibleBitmap(&dc, width, height))
    {
        return;
    }
    // 创建内存DC
    CDC srcDC;
    CDC dstDC;
    srcDC.CreateCompatibleDC(&dc);
    dstDC.CreateCompatibleDC(&dc);
    //m_selectedBitmap.CreateCompatibleBitmap(&dc, width, height);
    // 将位图选入DC
    CBitmap* pOldSrc = srcDC.SelectObject(&m_staticBitmap);
    CBitmap* pOldDst = dstDC.SelectObject(&m_selectedBitmap);

    // 获取源位图尺寸


    // 完全复制（BitBlt）
    dstDC.BitBlt(0, 0, width, height, &srcDC, 0, 0, SRCCOPY);

    // 清理
    srcDC.SelectObject(pOldSrc);
    {
        int CHESS_CELL_WIDTH = 58;
        int CHESS_START_X = 20;
        int CHESS_START_Y = 20;
        int posX = CHESS_START_X + m_selectedX * CHESS_CELL_WIDTH;
        int posY = CHESS_START_Y + m_selectedY * CHESS_CELL_WIDTH;
        COLORREF red(RGB(255, 0, 0));
        drawCornerMarks(&dstDC, posX, posY, CHESS_CELL_WIDTH, CHESS_CELL_WIDTH / 6, 3, red);
    }
    dstDC.SelectObject(pOldDst);


}

void CChessDialog::DoDataExchange(CDataExchange* pDX) {
    CDialog::DoDataExchange(pDX);
}

void CChessDialog::OnPaint() {
    CPaintDC dc(this);
    DrawPaintDC(&dc);
    // 背景色
    //dc.FillSolidRect(0, 0, 800, 700, RGB(200, 200, 200));
}

BOOL CChessDialog::PreCreateWindow(CREATESTRUCT& cs)
{
    if (!CDialog::PreCreateWindow(cs))
        return FALSE;

    // 在窗口创建前设置菜单
    //CreateMenuBar();
    //cs.hMenu = m_menu.GetSafeHmenu();

    return TRUE;
}

void CChessDialog::OnTimer(UINT_PTR nIDEvent)
{
    if (nIDEvent == TIMER_RENDER)
    {
        m_bDrawStaticBoard = !m_bDrawStaticBoard;
        Invalidate();
    }

    CDialog::OnTimer(nIDEvent);
}