// ChessDialog.h
#pragma once
#include <afxwin.h>
#include "CImageManager.h"
#include "ChessBoard.hpp"
#define WM_USER_UPDATE_INFO (WM_USER + 100)

#define TIMER_RENDER 1      // 渲染定时器ID
#define RENDER_FPS 60       // 60帧/秒
//#define RENDER_INTERVAL (1000 / RENDER_FPS)  // 约16.67ms
#define RENDER_INTERVAL 1000
class CChessDialog : public CDialog {
public:
    CChessDialog(CWnd* pParent = nullptr);
    
    // 对话框数据
    enum { IDD = 0 };  // 无资源，纯代码创建
    // 重写 DoModal 以支持无资源对话框
    virtual INT_PTR DoModal() override;
    BOOL CreateDialogWindow();
protected:
    virtual BOOL OnInitDialog();
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    
    void DrawPaintDC(CPaintDC* pDC);
    void DrawBoard(CPaintDC* pDC);
    void DrawChess(CPaintDC* pDC);
    // 消息处理
    afx_msg void OnTestStaticImage();
    afx_msg void OnTestSelectedImage();
    afx_msg void OnPaint();
    afx_msg void OnNewGame();
    afx_msg void OnChineseChess();
    afx_msg void OnAbout();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg LRESULT OnUpdateInfo(WPARAM, LPARAM);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    DECLARE_MESSAGE_MAP()
    
private:
    CMenu m_menu;

    // 渲染相关
    CRect m_boardRect;
    bool m_bDrawStaticBoard;
    CDC m_staticDC;           // 渲染DC（内存DC）
    CBitmap m_staticBitmap;   // 渲染位图

    CDC m_selectedDC;         //被选中时的DC
    CBitmap m_selectedBitmap;

    CRect m_clientRect;       // 客户区大小
    BOOL m_bNeedRedraw;       // 是否需要重绘标志

    ChessBoard m_board;
    CImageManager m_imageManager;
    int m_selectedX;
    int m_selectedY;
    void CreateMenuBar();
    void UpdateInfo();
    void UpdateStaticBitmap();
    void UpdateSelectedBitmap();
    void drawCornerMarks(CDC* pDC, int x, int y, int pieceSize, int cornerLen, int lineWidth, COLORREF color);
};