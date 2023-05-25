// okbb-macroDlg.cpp : implementation file
//

#include "stdafx.h"
#include "okbb-macro.h"
#include "okbb-macroDlg.h"
#include "afxdialogex.h"

#pragma comment(lib,"hidapi.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
    public:
        CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
        enum { IDD = IDD_ABOUTBOX };
#endif

    protected:
        virtual void DoDataExchange ( CDataExchange* pDX ); // DDX/DDV support

// Implementation
    protected:
        DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog ( IDD_ABOUTBOX )
{
}

void CAboutDlg::DoDataExchange ( CDataExchange* pDX )
{
    CDialog::DoDataExchange ( pDX );
}

BEGIN_MESSAGE_MAP ( CAboutDlg, CDialog )
END_MESSAGE_MAP()

// CokbbmacroDlg dialog

CokbbmacroDlg::CokbbmacroDlg ( CWnd* pParent /*=NULL*/ )
    : CDialog ( IDD_OKBBMACRO_DIALOG, pParent )
{
    m_hIcon = AfxGetApp()->LoadIcon ( IDR_MAINFRAME );
}

void CokbbmacroDlg::DoDataExchange ( CDataExchange* pDX )
{
    CDialog::DoDataExchange ( pDX );
    DDX_Control ( pDX, IDC_MACRO_STRING, m_Macro );
    DDX_Control ( pDX, IDR_WRITE_OKBB, m_Write );
    DDX_Control ( pDX, IDC_OKBB_SHRUGGIE, ಠ_ಠ );
    DDX_Control ( pDX, IDC_MESSAGE, m_Message );
    DDX_Control ( pDX, IDC_MACRO_STRING3, m_Unicode );
}

BEGIN_MESSAGE_MAP ( CokbbmacroDlg, CDialog )
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED ( IDR_WRITE_OKBB, &CokbbmacroDlg::OnBnClickedWriteOkbb )
END_MESSAGE_MAP()



WCHAR ｡｡[][60] = {
    _T ( "ˉ\\_(ツ)_/ˉ" ),
    _T ( "(͡° ͜ʖ ͡°)" ),
    _T ( "̿̿ ̿̿ ̿̿ ̿'̿'\\̵͇̿̿\\З= ( ▀ ͜͞ʖ▀) =Ε/̵͇̿̿/’̿’̿ ̿ ̿̿ ̿̿ ̿̿" ),
    _T ( "▄︻̷̿┻̿═━一" ),
    _T ( "( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°) ͡°)" ),
    _T ( "ʕ•ᴥ•ʔ" ),
    _T ( "(▀̿Ĺ̯▀̿ ̿)" ),
    _T ( "(ง ͠° ͟ل͜ ͡°)ง" ),
    _T ( "༼ つ ◕_◕ ༽つ" ),
    _T ( "ಠ_ಠ" ),
    _T ( "(づ｡◕‿‿◕｡)づ" ),
    _T ( "̿'̿'\\̵͇̿̿\\З=( ͠° ͟ʖ ͡°)=Ε/̵͇̿̿/'̿̿ ̿ ̿ ̿ ̿ ̿" ),
    _T ( "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ ✧ﾟ･: *ヽ(◕ヮ◕ヽ)" ),
    _T ( "[̲̅$̲̅(̲̅5̲̅)̲̅$̲̅]" ),
    _T ( "┬┴┬┴┤ ͜ʖ ͡°) ├┬┴┬┴" ),
    _T ( "( ͡°╭͜ʖ╮͡° )" ),
    _T ( "(͡ ͡° ͜ つ ͡͡°)" ),
    _T ( "(• Ε •)" ),
    _T ( "(ง'̀-'́)ง" ),
    _T ( "(ಥ﹏ಥ)" ),
    _T ( "﴾͡๏̯͡๏﴿ O'RLY?" ),
    _T ( "(ノಠ益ಠ)ノ彡┻━┻" ),
    _T ( "[̲̅$̲̅(̲̅ ͡° ͜ʖ ͡°̲̅)̲̅$̲̅]" ),
    _T ( "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧" ),
    _T ( "(☞ﾟ∀ﾟ)☞" ),
    _T ( "| (• ◡•)| (❍ᴥ❍Ʋ)" ),
    _T ( "(◕‿◕✿)" ),
    _T ( "(ᵔᴥᵔ)" ),
    _T ( "(╯°□°)╯︵ ꞰOOQƎƆⱯɟ" ),
    _T ( "(¬‿¬)" ),
    _T ( "(☞ﾟヮﾟ)☞ ☜(ﾟヮﾟ☜)" ),
    _T ( "(づ￣ ³￣)づ" ),
    _T ( "ლ(ಠ益ಠლ)" ),
    _T ( "ಠ╭╮ಠ" ),
    _T ( "̿ ̿ ̿'̿'\\̵͇̿̿\\З=(•_•)=Ε/̵͇̿̿/'̿'̿ ̿" ),
    _T ( "/╲/\\╭( ͡° ͡° ͜ʖ ͡° ͡°)╮/\\╱\\" ),
    _T ( "(;´༎ຶД༎ຶ`)" ),
    _T ( "♪~ ᕕ(ᐛ)ᕗ" ),
    _T ( "♥‿♥" ),
    _T ( "༼ つ ͡° ͜ʖ ͡° ༽つ" ),
    _T ( "༼ つ ಥ_ಥ ༽つ" ),
    _T ( "(╯°□°）╯︵ ┻━┻" ),
    _T ( "( ͡ᵔ ͜ʖ ͡ᵔ )" ),
    _T ( "ヾ(⌐■_■)ノ♪" ),
    _T ( "~(˘▾˘~)" ),
    _T ( "◉_◉" ),
    _T ( "\\ (•◡•) /" ),
    _T ( "(~˘▾˘)~" ),
    _T ( "(._.) ( L: ) ( .-. ) ( :L ) (._.)" ),
    _T ( "༼ʘ̚ل͜ʘ̚༽" ),
    _T ( "༼ ºل͟º ༼ ºل͟º ༼ ºل͟º ༽ ºل͟º ༽ ºل͟º ༽" ),
    _T ( "┬┴┬┴┤(･_├┬┴┬┴" ),
    _T ( "ᕙ(⇀‸↼‶)ᕗ" ),
    _T ( "ᕦ(Ò_Óˇ)ᕤ" ),
    _T ( "┻━┻ ︵ヽ(`Д´)ﾉ︵ ┻━┻" ),
    _T ( "⚆ _ ⚆" ),
    _T ( "(•_•) ( •_•)>⌐■-■ (⌐■_■)" ),
    _T ( "(｡◕‿‿◕｡)" ),
    _T ( "ಥ_ಥ" ),
    _T ( "ヽ༼ຈل͜ຈ༽ﾉ" ),
    _T ( "⌐╦╦═─" ),
    _T ( "(☞ຈل͜ຈ)☞" ),
    _T ( "˙ ͜ʟ˙" ),
    _T ( "☜(˚▽˚)☞" ),
    _T ( "(•Ω•)" ),
    _T ( "(ง°ل͜°)ง" ),
    _T ( "(｡◕‿◕｡)" ),
    _T ( "（╯°□°）╯︵( .O.)" ),
    _T ( ":')" ),
    _T ( "┬──┬ ノ( ゜-゜ノ)" ),
    _T ( "(っ˘ڡ˘Σ)" ),
    _T ( "ಠ⌣ಠ" ),
    _T ( "ლ(´ڡ`ლ)" ),
    _T ( "(°ロ°)☝" ),
    _T ( "｡◕‿‿◕｡" ),
    _T ( "( ಠ ͜ʖರೃ)" ),
    _T ( "╚(ಠ_ಠ)=┐" ),
    _T ( "(─‿‿─)" ),
    _T ( "ƪ(˘⌣˘)Ʃ" ),
    _T ( "(；一_一)" ),
    _T ( "(¬_¬)" ),
    _T ( "( ⚆ _ ⚆ )" ),
    _T ( "(ʘᗩʘ')" ),
    _T ( "☜(⌒▽⌒)☞" ),
    _T ( "｡◕‿◕｡" ),
    _T ( "¯\\(°_O)/¯" ),
    _T ( "(ʘ‿ʘ)" ),
    _T ( "ლ,ᔑ•ﺪ͟͠•ᔐ.ლ" ),
    _T ( "(´・Ω・`)" ),
    _T ( "ಠ~ಠ" ),
    _T ( "(° ͡ ͜ ͡ʖ ͡ °)" ),
    _T ( "┬─┬ノ( º _ ºノ)" ),
    _T ( "(´・Ω・)っ由" ),
    _T ( "ಠ_ಥ" ),
    _T ( "Ƹ̵̡Ӝ̵̨̄Ʒ" ),
    _T ( "(>ლ)" ),
    _T ( "ಠ‿↼" ),
    _T ( "ʘ‿ʘ" ),
    _T ( "(ღ˘⌣˘ღ)" ),
    _T ( "ಠOಠ" ),
    _T ( "ರ_ರ" ),
    _T ( "(▰˘◡˘▰)" ),
    _T ( "◔̯◔" ),
    _T ( "◔ ⌣ ◔" ),
    _T ( "(✿´‿`)" ),
    _T ( "¬_¬" ),
    _T ( "ب_ب" ),
    _T ( "｡゜(｀Д´)゜｡" ),
    _T ( "(Ó Ì_Í)=ÓÒ=(Ì_Í Ò)" ),
    _T ( "°Д°" ),
    _T ( "( ﾟヮﾟ)" ),
    _T ( "┬─┬﻿ ︵ /(.□. ）" ),
    _T ( "٩◔̯◔۶" ),
    _T ( "≧☉_☉≦" ),
    _T ( "☼.☼" ),
    _T ( "^̮^" ),
    _T ( "(>人<)" ),
    _T ( "〆(・∀・＠)" ),
    _T ( "(~_^)" ),
    _T ( "^̮^" ),
    _T ( "^̮^" ),
    _T ( ">_>" ),
    _T ( "(^̮^)" ),
    _T ( "(/) (°,,°) (/)" ),
    _T ( "^̮^" ),
    _T ( "=U" ),
    _T ( "(･.◤)" ),
    _T ( "(∩ ͡ ° ʖ ͡ °) ⊃-(===>" ),
    _T ( "╰( ͡° ͜ʖ ͡° )つ──☆*:・ﾟ" ),
    _T ( "┴┬┴┤( ͡° ͜ʖ├┬┴┬" ),
    _T ( "( ʘ̆ ╭͜ʖ╮ ʘ̆ )" ),
    _T ( "( ͡ຈ╭͜ʖ╮͡ຈ )" ),
    _T ( "( ͡° ͜ʖ ͡°)" ),
    _T ( "( ͡°╭͜ʖ╮͡° )" ),
    _T ( "(ノ͡° ͜ʖ ͡°)ノ︵┻┻" ),
    _T ( "( ͡~ ͜ʖ ͡~)" ),
    _T ( "( ͝סּ ͜ʖ͡סּ)" ),
    _T ( "☆*。★ﾟ*♪ヾ(☆ゝз・)ノ" ),
    _T ( "✿♥‿♥✿" ),
    _T ( "（♥￫ｏ￩♥）" ),
    _T ( "♱♡‿♡♰" ),
    _T ( "༼♥ل͜♥༽" ),
    _T ( "♪～(￣ε￣)" ),
    _T ( "･｡ﾟ[̲̅$̲̅(̲̅ ͡° ͜ʖ ͡°̲̅)̲̅$̲̅]｡ﾟ.*" ),

    NULL


};

// CokbbmacroDlg message handlers

void pressKeyLALT2 ( unsigned short value )
{
    _RPT4 ( _CRT_WARN, "\n0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
            ( ( value >> 8 ) & 0xf0 ) >> 4, ( ( value >> 8 ) & 0x0f ), ( value & 0xf0 ) >> 4, value & 0x0f
          );

}

BOOL CokbbmacroDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // Add "About..." menu item to system menu.

    // IDM_ABOUTBOX must be in the system command range.
    ASSERT ( ( IDM_ABOUTBOX & 0xFFF0 ) == IDM_ABOUTBOX );
    ASSERT ( IDM_ABOUTBOX < 0xF000 );

    CMenu* pSysMenu = GetSystemMenu ( FALSE );

    if ( pSysMenu != NULL ) {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString ( IDS_ABOUTBOX );
        ASSERT ( bNameValid );

        if ( !strAboutMenu.IsEmpty() ) {
            pSysMenu->AppendMenu ( MF_SEPARATOR );
            pSysMenu->AppendMenu ( MF_STRING, IDM_ABOUTBOX, strAboutMenu );
        }
    }

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon ( m_hIcon, TRUE );			// Set big icon
    SetIcon ( m_hIcon, FALSE );		// Set small icon

    // TODO: Add extra initialization here

    // mark as dead
    handle = ( hid_device* ) 0xdead;

    // last char needs to be 0
    m_Macro.SetLimitText ( 127 );
    m_Unicode.SetLimitText ( 127 );

    // clear out our flash buffer
    memset ( uploadBuffer, 0, sizeof ( uploadBuffer ) );

    // enable write ( meant to only enable after text or emoticon chosen
    m_Write.EnableWindow ( TRUE );

    // convert, populate shruggies
    int i = 0;

    do {

        _RPT1 ( _CRT_WARN, "\t\tcase %d :\n", i );

        ಠ_ಠ.AddString ( ｡｡[i] );

        //Convert ( shruggies[i] );

        _RPT0 ( _CRT_WARN, "\t\t\tbreak;\n\n" );
        i++;

    } while ( wcslen ( ｡｡[i] )  );

    m_font.CreatePointFont ( 150, _T ( "Segoe UI" ) );
    ಠ_ಠ.SetFont ( &m_font );

    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CokbbmacroDlg::Convert ( WCHAR *str )
{
    char tempBuffer[20];
    char tempBuffer1[20];
    int length;
    unsigned char *pBuffer = uploadBuffer;

    // clear buffer;
    memset ( uploadBuffer, 0, sizeof ( uploadBuffer ) );

    length = wcslen ( str );

    // 3 for the mode+type+length
    //
    if ( ( length * 2 ) >= 128 - 3 ) {
        _RPT0 ( _CRT_WARN, "\t\t\t//Skipped too long" );
        return;
    }

    if ( 1 ) {

        // custom string, not text
        *pBuffer++ = 0xff;

        // mode, scan codes
        *pBuffer++ = 0x02;

        // length of scan codes
        *pBuffer++ = length;

        for ( int i = 0; i < length; i++ ) {

            _RPT1 ( _CRT_WARN, "\t\t\tpressKeyLALT2 ( 0x%04x ) ; //", str[i] );

            snprintf ( tempBuffer, sizeof ( tempBuffer ) - 1, "%04x", str[i] );

            // pressKeyLALT2 ( str[i] );

            *pBuffer++ = str[i] >> 8;
            *pBuffer++ = str[i] & 0xff;

            for ( unsigned int j = 0; j < 4; j++ ) {

                snprintf ( tempBuffer1, sizeof ( tempBuffer1 ) - 1, "KEY_%c", toupper ( tempBuffer[j] ) );

                _RPT1 ( _CRT_WARN, "%s", tempBuffer1 );

                if ( j != 3 ) {

                    _RPT0 ( _CRT_WARN, "," );

                } else {
                    _RPT2 ( _CRT_WARN, " ); // %d %d\n", length, length * 2 );

                }

            }

        }
    }

    if ( 0 ) {
        // _RPT0 ( _CRT_WARN, "BYTE keyCodes[] = {\n" );

        for ( unsigned int i = 0; i < wcslen ( str ); i++ ) {
            _RPT0 ( _CRT_WARN, "\t" );

            snprintf ( tempBuffer, sizeof ( tempBuffer ) - 1, "%04x", str[i] );

            for ( unsigned int j = 0; j < 4; j++ ) {

                snprintf ( tempBuffer1, sizeof ( tempBuffer1 ) - 1, "KEY_%c", toupper ( tempBuffer[j] ) );
                _RPT1 ( _CRT_WARN, "%s", tempBuffer1 );

                if ( j != 3 ) {
                    _RPT0 ( _CRT_WARN, "," );

                } else {
                    _RPT0 ( _CRT_WARN, ",\n" );

                }
            }
        }
    }
}

void CokbbmacroDlg::OnSysCommand ( UINT nID, LPARAM lParam )
{
    if ( ( nID & 0xFFF0 ) == IDM_ABOUTBOX ) {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();

    } else {
        CDialog::OnSysCommand ( nID, lParam );
    }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CokbbmacroDlg::OnPaint()
{
    if ( IsIconic() ) {
        CPaintDC dc ( this ); // device context for painting

        SendMessage ( WM_ICONERASEBKGND, reinterpret_cast<WPARAM> ( dc.GetSafeHdc() ), 0 );

        // Center icon in client rectangle
        int cxIcon = GetSystemMetrics ( SM_CXICON );
        int cyIcon = GetSystemMetrics ( SM_CYICON );
        CRect rect;
        GetClientRect ( &rect );
        int x = ( rect.Width() - cxIcon + 1 ) / 2;
        int y = ( rect.Height() - cyIcon + 1 ) / 2;

        // Draw the icon
        dc.DrawIcon ( x, y, m_hIcon );

    } else {
        CDialog::OnPaint();
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CokbbmacroDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR> ( m_hIcon );
}

void CokbbmacroDlg::PostNcDestroy()
{
    if ( handle != ( hid_device* ) 0xDead ) {

        hid_close ( handle );
        handle = ( hid_device* ) 0xDead;

    }

    CDialog::PostNcDestroy();
}

int  CokbbmacroDlg::uploadToFlash ( unsigned char *inputBuffer )
{
    unsigned char tempBuffer[20];
    int res;

    if ( inputBuffer == NULL ) {
        return -1;
    }

    memset ( tempBuffer, 0, sizeof ( tempBuffer ) );

    tempBuffer[ 0 ] = 0;

    // write to internal buffer
    tempBuffer[ 1 ] = 0xfe;

    for ( unsigned int index = 0; index < 16; index++ ) {

        // 0..15 index for offset of internal buffer to write 8 bytes too
        tempBuffer[ 2 ] = index;

        // buf 3 to 3+8 is the data
        memcpy ( &tempBuffer[3], inputBuffer, 8 );

        // skip into buffer
        inputBuffer += 8;

		_RPT4(_CRT_WARN, "uploadToFlash  [0x%02x] [%d] [%s] [%d]\n", tempBuffer[1] , tempBuffer[2] , &tempBuffer[3], 16);

        //write to HID
        res = hid_write ( handle, tempBuffer, 16 + 1 );
        if (res == -1) {
            return res;
        }
    }

    tempBuffer[0] = 0;
    // write from internal ram to flash(HE)
    tempBuffer[1] = 0xfd;

    res = hid_write ( handle, tempBuffer, 16 + 1 );

    return res;
}

void CokbbmacroDlg::OnBnClickedWriteOkbb()
{
    unsigned char tempBuffer[32];

    handle = hid_open ( 0x0032, 0x0808, NULL );

    if ( !handle ) {

        m_Message.SetWindowText ( _T ( "Can't open OKKB HID Interface" ) );

        return;

    }

    m_Message.SetWindowText ( _T ( "Opened OKKB" ) );

    CString str;
    CStringA utf8;
    memset ( tempBuffer, 0, sizeof ( tempBuffer ) );

    if ( ಠ_ಠ.GetCurSel() != -1 ) {

        // this preps it for upload into the uploadBuffer
        Convert ( ｡｡[ಠ_ಠ.GetCurSel() ] );

        m_Message.SetWindowText ( _T ( "Setting OKKB to emoticon uploader" ) );

        int res = uploadToFlash ( uploadBuffer );

        if ( res < 0 ) {

            AfxMessageBox ( _T ( "Wasn't able to write to OKKB HID Interface" ), 0, 0 );
            hid_close ( handle );
            handle = ( hid_device* ) 0xDead;


            return;
        }

        m_Message.SetWindowText ( _T ( "Wrote to OKKB HID Interface emoticon" ) );

        hid_close ( handle );
        handle = ( hid_device* ) 0xDead;

        return;
    }

    m_Unicode.GetWindowText ( str );
    int len = str.GetLength();

    if ( len ) {

        // this preps it into the uploadBuffer
        Convert ( str.GetBuffer()  );
        str.ReleaseBuffer();

        m_Message.SetWindowText ( _T ( "Setting OKKB to unicode uploader" ) );

        int res = uploadToFlash ( uploadBuffer );

        if ( res < 0 ) {

            AfxMessageBox ( _T ( "Wasn't able to write to OKKB HID Interface" ), 0, 0 );
            hid_close ( handle );

            handle = ( hid_device* ) 0xDead;

            return;
        }

        m_Message.SetWindowText ( _T ( "Wrote to OKKB HID Interface unicode" ) );

        hid_close ( handle );
        handle = ( hid_device* ) 0xDead;

        return;
    }

    m_Macro.GetWindowText ( str );
    utf8 = str;
    len = utf8.GetLength();

    if ( len == 0 ) {
        AfxMessageBox ( _T ( "Nothing to write !\n\nEither choose an emoticon above, or enter some text below" ), 0, 0 );

        if ( handle != ( hid_device* ) 0xDead ) {
            hid_close ( handle );
            handle = ( hid_device* ) 0xDead;

        }

        return;
    }

    // empty it
    memset ( uploadBuffer, 0, sizeof ( uploadBuffer ) );

    // copy to uploadBuffer
    memcpy ( uploadBuffer, utf8.GetBuffer(), len );
    utf8.ReleaseBuffer();

	_RPT2(_CRT_WARN, "p1 [%s] [%d]\n", uploadBuffer, len);
	int res = uploadToFlash ( uploadBuffer );

    if ( res < 0 ) {

        m_Message.SetWindowText ( _T ( "Wasn't able to write to OKKB HID Interface" ) );

        hid_close ( handle );
        handle = ( hid_device* ) 0xDead;

        return;
    }
	
	m_Message.SetWindowText(_T("Wrote plain text"));


    const int blockLenth = 15;

    len = utf8.GetLength();

    if ( len > blockLenth) {


        len -= blockLenth;

        if ( len > blockLenth) {
            len = blockLenth;
        }

        memset ( tempBuffer, 0, sizeof ( tempBuffer ) );
#if 0
        tempBuffer[0] = 0;
        tempBuffer[1] = 0xff;


        memcpy ( &tempBuffer[2], utf8.GetBuffer(), len );

		_RPT2(_CRT_WARN, "p2 [%s] [%d]\n", tempBuffer, len);
        // 0x0 + 0xff + block 
        res = hid_write ( handle, tempBuffer, blockLenth + 1 + 1 );


        if ( res < 0 ) {
            AfxMessageBox ( _T ( "Wasn't able to write to OKKB HID Interface plain text" ), 0, 0 );
            return;
        }
#endif

   // finalise to flash
        tempBuffer[0] = 0;
        tempBuffer[1] = 0xfd;

        int res = hid_write ( handle, tempBuffer, blockLenth + 1 + 1);

        m_Message.SetWindowText ( _T ( "Wrote string to OKKB plain text" ) );

    }
    hid_close(handle);
    handle = (hid_device*)0xDead;

}
/*
*	abcdefghijklmnopqrstuvwxyz
	abcdefghijklmnoabcdefghijk
			  1         2    
	01234567890123456789012345
*/
