
// okbb-macroDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CokbbmacroDlg dialog
class CokbbmacroDlg : public CDialog
{
// Construction
    public:
        CokbbmacroDlg ( CWnd* pParent = NULL );	// standard constructor
        void Convert ( WCHAR *str );
        int uploadToFlash ( unsigned char *inputBuffer );

// Dialog Data
#ifdef AFX_DESIGN_TIME
        enum { IDD = IDD_OKBBMACRO_DIALOG };
#endif

    protected:
        virtual void DoDataExchange ( CDataExchange* pDX );	// DDX/DDV support


// Implementation
    protected:
        HICON m_hIcon;
        hid_device *handle;
        unsigned char uploadBuffer[128];
        CFont m_font;
        // Generated message map functions
        virtual BOOL OnInitDialog();
        afx_msg void OnSysCommand ( UINT nID, LPARAM lParam );
        afx_msg void OnPaint();
        afx_msg HCURSOR OnQueryDragIcon();
        DECLARE_MESSAGE_MAP()
    public:
        CEdit m_Macro;
        afx_msg void OnBnClickedOpenOkbb();
        CButton m_Write;
        virtual void PostNcDestroy();
        afx_msg void OnBnClickedWriteOkbb();
        CListBox  ಠ_ಠ;
        CEdit m_Message;
        CEdit m_Unicode;
};
