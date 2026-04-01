// main.cpp
#include <afxwin.h>
#include "ChessDialog.h"

class CChessApp : public CWinApp
{
public:
    virtual BOOL InitInstance()
    {
        CChessDialog dlg;
        m_pMainWnd = &dlg;
        dlg.DoModal();
        return FALSE;  // 对话框关闭后退出
    }
};

CChessApp theApp;