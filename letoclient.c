
//#define _UNICODE
//#define UNICODE

#include "_cgo_export.h"
#include <stdio.h>
#include "cletocl.h"

#if defined( WINNT ) || defined( _Windows ) || defined( __NT__ ) || defined( _WIN32 ) || defined( _WINDOWS_ ) || defined( __WINDOWS_386__ ) || defined( __WIN32__ )
   #define _OS_WIN
   #define PDYN WINAPI*
   HMODULE hLeto = NULL;
#else
   #include <dlfcn.h>
   #define PDYN *
   void* hLeto = NULL;
#endif

typedef void( PDYN LPLetoInit ) ( void );
typedef void ( PDYN LPLetoExit) ( unsigned int uiFull );
typedef LETOCONNECTION * ( PDYN LPLetoConnectionNew) ( const char * szAddr, int iPort, const char * szUser, const char * szPass, int iTimeOut );
typedef void ( PDYN LPLetoConnectionClose) ( LETOCONNECTION * pConnection );
typedef char * ( PDYN LPLetoGetServerVer) ( LETOCONNECTION * pConnection );
typedef LETOTABLE * ( PDYN LPLetoDbCreateTable ) ( LETOCONNECTION * pConnection, char * szFile, char * szAlias, char * szFields, unsigned int uiArea );
typedef LETOTABLE * ( PDYN LPLetoDbOpenTable ) ( LETOCONNECTION * pConnection, char * szFile, char * szAlias, int iShared, int iReadOnly, char * szCdp, unsigned int uiArea, char * szDataFileName, unsigned int uiDFNLen );
typedef unsigned int ( PDYN LPLetoDbCloseTable ) ( LETOTABLE * pTable );
typedef unsigned int ( PDYN LPLetoDbBof ) ( LETOTABLE * pTable );
typedef unsigned int ( PDYN LPLetoDbEof ) ( LETOTABLE * pTable );
typedef unsigned int ( PDYN LPLetoDbRecCount ) ( LETOTABLE * pTable, unsigned long * ulCount );
typedef unsigned int ( PDYN LPLetoDbGoTop ) ( LETOTABLE * pTable, char * szTag );
typedef unsigned int ( PDYN LPLetoDbGoBottom ) ( LETOTABLE * pTable, char * szTag );
typedef unsigned int ( PDYN LPLetoDbGoTo ) ( LETOTABLE * pTable, unsigned long ulRecNo, char * szTag );
typedef unsigned int ( PDYN LPLetoDbSkip ) ( LETOTABLE * pTable, long lToSkip, char * szTag );
typedef unsigned int ( PDYN LPLetoDbRecNo ) ( LETOTABLE * pTable, unsigned long * ulRecNo );
typedef unsigned int ( PDYN LPLetoDbPutField ) ( LETOTABLE * pTable, unsigned int uiIndex, char * szValue, unsigned int uiLen );
typedef unsigned int ( PDYN LPLetoDbGetField ) ( LETOTABLE * pTable, unsigned int uiIndex, char * szRet, unsigned int * uiLen );
typedef char * ( PDYN LPLetoDbGetMemo ) ( LETOTABLE * pTable, unsigned int uiIndex, unsigned long * ulLen );
typedef unsigned int ( PDYN LPLetoDbPutMemo ) ( LETOTABLE * pTable, unsigned int uiIndex, const char * szValue, unsigned long ulLenMemo );
typedef unsigned int ( PDYN LPLetoDbAppend ) ( LETOTABLE * pTable, unsigned int fUnLockAll );
typedef unsigned int ( PDYN LPLetoDbPutRecord ) ( LETOTABLE * pTable, unsigned int bCommit );
typedef unsigned int ( PDYN LPLetoDbFieldCount ) ( LETOTABLE * pTable, unsigned int * uiCount );
typedef unsigned int ( PDYN LPLetoDbFieldName ) ( LETOTABLE * pTable, unsigned int uiIndex, char * szName );
typedef unsigned int ( PDYN LPLetoDbFieldType ) ( LETOTABLE * pTable, unsigned int uiIndex, unsigned int * uiType );
typedef unsigned int ( PDYN LPLetoDbFieldLen ) ( LETOTABLE * pTable, unsigned int uiIndex, unsigned int * uiLen );
typedef unsigned int ( PDYN LPLetoDbFieldDec ) ( LETOTABLE * pTable, unsigned int uiIndex, unsigned int * uiDec );
typedef unsigned int ( PDYN LPLetoDbOrderCreate ) ( LETOTABLE * pTable, char * szBagName, char * szTag, char * szKey, unsigned char bType, unsigned int uiFlags, char * szFor, char * szWhile, unsigned long ulNext );
typedef unsigned int ( PDYN LPLetoDbOrderFocus) ( LETOTABLE * pTable, char * szTagName, unsigned int uiOrder );
typedef unsigned int ( PDYN LPLetoDbSeek ) ( LETOTABLE * pTable, char * szTag, const char * szKey, unsigned int uiKeyLen, unsigned int bSoftSeek, unsigned int bFindLast );
typedef unsigned int ( PDYN LPLetoDbRecLock ) ( LETOTABLE * pTable, unsigned long ulRecNo );
typedef unsigned int ( PDYN LPLetoDbRecUnLock ) ( LETOTABLE * pTable, unsigned long ulRecNo );
typedef unsigned int ( PDYN LPLetoDbIsRecLocked ) ( LETOTABLE * pTable, unsigned long ulRecNo, unsigned int * uiRes );
typedef unsigned int ( PDYN LPLetoDbDelete ) ( LETOTABLE * pTable );
typedef unsigned int ( PDYN LPLetoDbRecall ) ( LETOTABLE * pTable );

LPLetoInit fLetoInit = NULL;
LPLetoExit fLetoExit = NULL;
LPLetoConnectionNew fLetoConnectionNew = NULL;
LPLetoConnectionClose fLetoConnectionClose = NULL;
LPLetoGetServerVer fLetoGetServerVer = NULL;
LPLetoDbCreateTable fLetoDbCreateTable = NULL;
LPLetoDbOpenTable fLetoDbOpenTable = NULL;
LPLetoDbCloseTable fLetoDbCloseTable = NULL;
LPLetoDbBof fLetoDbBof = NULL;
LPLetoDbEof fLetoDbEof = NULL;
LPLetoDbRecCount fLetoDbRecCount = NULL;
LPLetoDbGoTop fLetoDbGoTop = NULL;
LPLetoDbGoBottom fLetoDbGoBottom = NULL;
LPLetoDbGoTo fLetoDbGoTo = NULL;
LPLetoDbSkip fLetoDbSkip = NULL;
LPLetoDbRecNo fLetoDbRecNo = NULL;
LPLetoDbPutField fLetoDbPutField = NULL;
LPLetoDbGetField fLetoDbGetField = NULL;
LPLetoDbGetMemo fLetoDbGetMemo = NULL;
LPLetoDbPutMemo fLetoDbPutMemo = NULL;
LPLetoDbAppend fLetoDbAppend = NULL;
LPLetoDbPutRecord fLetoDbPutRecord = NULL;
LPLetoDbFieldCount fLetoDbFieldCount = NULL;
LPLetoDbFieldName fLetoDbFieldName = NULL;
LPLetoDbFieldType fLetoDbFieldType = NULL;
LPLetoDbFieldLen fLetoDbFieldLen = NULL;
LPLetoDbFieldDec fLetoDbFieldDec = NULL;
LPLetoDbOrderCreate fLetoDbOrderCreate = NULL;
LPLetoDbOrderFocus fLetoDbOrderFocus = NULL;
LPLetoDbSeek fLetoDbSeek = NULL;
LPLetoDbRecLock fLetoDbRecLock = NULL;
LPLetoDbRecUnLock fLetoDbRecUnLock = NULL;
LPLetoDbIsRecLocked fLetoDbIsRecLocked = NULL;
LPLetoDbDelete fLetoDbDelete = NULL;
LPLetoDbRecall fLetoDbRecall = NULL;

static char * pBuffer = NULL;
static unsigned int iBufLen = 0;

#if defined( _OS_WIN )
int leto_LoadLib( void )
{
   if( !hLeto )
   {
      //hLeto = LoadLibrary( L"letocl_uni.dll" );
      hLeto = LoadLibrary( "letocl.dll" );

      if( hLeto )
      {
         fLetoInit = ( LPLetoInit ) GetProcAddress( hLeto, "_LetoInit" );
         fLetoExit = ( LPLetoExit ) GetProcAddress( hLeto, "_LetoExit" );
         fLetoConnectionNew = ( LPLetoConnectionNew ) GetProcAddress( hLeto, "_LetoConnectionNew" );
         fLetoDbOpenTable = ( LPLetoDbOpenTable ) GetProcAddress( hLeto, "_LetoDbOpenTable" );
         fLetoDbCloseTable = ( LPLetoDbCloseTable ) GetProcAddress( hLeto, "_LetoDbCloseTable" );
         fLetoDbBof = ( LPLetoDbBof ) GetProcAddress( hLeto, "_LetoDbBof" );
         fLetoDbEof = ( LPLetoDbEof ) GetProcAddress( hLeto, "_LetoDbEof" );
         fLetoDbRecCount = ( LPLetoDbRecCount) GetProcAddress( hLeto, "_LetoDbRecCount" );

         fLetoDbGoTop = ( LPLetoDbGoTop ) GetProcAddress( hLeto, "_LetoDbGoTop" );
         fLetoDbGoBottom = ( LPLetoDbGoBottom ) GetProcAddress( hLeto, "_LetoDbGoBottom" );
         fLetoDbGoTo = ( LPLetoDbGoTo ) GetProcAddress( hLeto, "_LetoDbGoTo" );
         fLetoDbSkip = ( LPLetoDbSkip ) GetProcAddress( hLeto, "_LetoDbSkip" );
         fLetoDbRecNo = ( LPLetoDbRecNo ) GetProcAddress( hLeto, "_LetoDbRecNo" );

         fLetoDbPutField = ( LPLetoDbPutField ) GetProcAddress( hLeto, "_LetoDbPutField" );
         fLetoDbGetField = ( LPLetoDbGetField ) GetProcAddress( hLeto, "_LetoDbGetField" );
         fLetoDbGetMemo = ( LPLetoDbGetMemo ) GetProcAddress( hLeto, "_LetoDbGetMemo" );
         fLetoDbPutMemo = ( LPLetoDbPutMemo ) GetProcAddress( hLeto, "_LetoDbPutMemo" );
         fLetoDbAppend = ( LPLetoDbAppend ) GetProcAddress( hLeto, "_LetoDbAppend" );
         fLetoDbPutRecord = ( LPLetoDbPutRecord ) GetProcAddress( hLeto, "_LetoDbPutRecord" );

         fLetoDbFieldLen = ( LPLetoDbFieldLen ) GetProcAddress( hLeto, "_LetoDbFieldLen" );
         fLetoDbFieldDec = ( LPLetoDbFieldDec ) GetProcAddress( hLeto, "_LetoDbFieldDec" );

         fLetoDbOrderCreate = ( LPLetoDbOrderCreate ) GetProcAddress( hLeto, "_LetoDbOrderCreate" );
         fLetoDbOrderFocus = ( LPLetoDbOrderFocus ) GetProcAddress( hLeto, "_LetoDbOrderFocus" );
         fLetoDbSeek = ( LPLetoDbSeek ) GetProcAddress( hLeto, "_LetoDbSeek" );
         fLetoDbRecLock = ( LPLetoDbRecLock ) GetProcAddress( hLeto, "_LetoDbRecLock" );
         fLetoDbRecUnLock = ( LPLetoDbRecUnLock ) GetProcAddress( hLeto, "_LetoDbRecUnLock" );
         fLetoDbIsRecLocked = ( LPLetoDbIsRecLocked ) GetProcAddress( hLeto, "_LetoDbIsRecLocked" );
         //printf( "%d %d %d %d %d %d\r\n", (hLeto)? 1:0, (fLetoInit)? 1:0, (fLetoExit)? 1:0, (fLetoConnectionNew)? 1:0, (fLetoConnectionClose)? 1:0, (fLetoGetServerVer)? 1:0 );
         fLetoInit();
         iBufLen = 256;
         pBuffer = (char*) malloc( iBufLen );
         return 1;
      }
   }
   return 0;
}

#else

int leto_LoadLib( void )
{

   if( !hLeto )
   {
      hLeto = dlopen( "./libletocl.so", RTLD_LAZY );
      if( hLeto )
      {
         fLetoInit = ( LPLetoInit ) dlsym( hLeto, "LetoInit" );
         fLetoExit = ( LPLetoExit ) dlsym( hLeto, "LetoExit" );
         fLetoConnectionNew = ( LPLetoConnectionNew ) dlsym( hLeto, "LetoConnectionNew" );
         fLetoDbOpenTable = ( LPLetoDbOpenTable ) dlsym( hLeto, "LetoDbOpenTable" );
         fLetoDbCloseTable = ( LPLetoDbCloseTable ) dlsym( hLeto, "LetoDbCloseTable" );
         fLetoDbBof = ( LPLetoDbBof ) dlsym( hLeto, "LetoDbBof" );
         fLetoDbBof = ( LPLetoDbEof ) dlsym( hLeto, "LetoDbEof" );
         fLetoDbRecCount = ( LPLetoDbRecCount) dlsym( hLeto, "LetoDbRecCount" );

         fLetoDbGoTop = ( LPLetoDbGoTop ) dlsym( hLeto, "LetoDbGoTop" );
         fLetoDbGoTo = ( LPLetoDbGoTo ) dlsym( hLeto, "LetoDbGoTo" );
         fLetoDbGoBottom = ( LPLetoDbGoBottom ) dlsym( hLeto, "LetoDbGoBottom" );
         fLetoDbSkip = ( LPLetoDbSkip ) dlsym( hLeto, "LetoDbSkip" );
         fLetoDbRecNo = ( LPLetoDbRecNo ) dlsym( hLeto, "LetoDbRecNo" );

         fLetoDbPutField = ( LPLetoDbPutField ) dlsym( hLeto, "LetoDbPutField" );
         fLetoDbGetField = ( LPLetoDbGetField ) dlsym( hLeto, "LetoDbGetField" );
         fLetoDbGetMemo = ( LPLetoDbGetMemo ) dlsym( hLeto, "LetoDbGetMemo" );
         fLetoDbPutMemo = ( LPLetoDbPutMemo ) dlsym( hLeto, "LetoDbPutMemo" );
         fLetoDbAppend = ( LPLetoDbAppend ) dlsym( hLeto, "LetoDbAppend" );
         fLetoDbPutRecord = ( LPLetoDbPutRecord ) dlsym( hLeto, "LetoDbPutRecord" );

         fLetoDbFieldLen = ( LPLetoDbFieldLen ) dlsym( hLeto, "LetoDbFieldLen" );
         fLetoDbFieldDec = ( LPLetoDbFieldDec ) dlsym( hLeto, "LetoDbFieldDec" );
         fLetoDbOrderCreate = ( LPLetoDbOrderCreate ) dlsym( hLeto, "LetoDbOrderCreate" );
         fLetoDbOrderFocus = ( LPLetoDbOrderFocus ) dlsym( hLeto, "LetoDbOrderFocus" );
         fLetoDbSeek = ( LPLetoDbSeek ) dlsym( hLeto, "LetoDbSeek" );
         fLetoDbRecLock = ( LPLetoDbRecLock ) dlsym( hLeto, "LetoDbRecLock" );
         fLetoDbRecUnLock = ( LPLetoDbRecUnLock ) dlsym( hLeto, "LetoDbRecUnLock" );
         fLetoDbIsRecLocked = ( LPLetoDbIsRecLocked ) dlsym( hLeto, "LetoDbIsRecLocked" );

         fLetoInit();
         iBufLen = 256;
         pBuffer = (char*) malloc( iBufLen );
         return 1;
      }
   }
   return 0;
}
#endif

void leto_UnLoadLib( void )
{
   if( hLeto )
   {
#if defined( _OS_WIN )
      FreeLibrary( hLeto );
#else
      dlclose( hLeto );
#endif
      hLeto = NULL;
      fLetoInit = NULL;
      fLetoExit = NULL;
      fLetoConnectionNew = NULL;
      fLetoConnectionClose = NULL;
      fLetoGetServerVer = NULL;
      fLetoDbCreateTable = NULL;
      fLetoDbOpenTable = NULL;
      fLetoDbCloseTable = NULL;
      fLetoDbBof = NULL;
      fLetoDbEof = NULL;
      fLetoDbRecCount = NULL;
      fLetoDbGoTop = NULL;
      fLetoDbGoBottom = NULL;
      fLetoDbGoTo = NULL;
      fLetoDbSkip = NULL;
      fLetoDbRecNo = NULL;
      fLetoDbPutField = NULL;
      fLetoDbGetField = NULL;
      fLetoDbGetMemo = NULL;
      fLetoDbPutMemo = NULL;
      fLetoDbAppend = NULL;
      fLetoDbPutRecord = NULL;
      fLetoDbFieldCount = NULL;
      fLetoDbFieldName = NULL;
      fLetoDbFieldType = NULL;
      fLetoDbFieldLen = NULL;
      fLetoDbFieldDec = NULL;
      fLetoDbOrderCreate = NULL;
      fLetoDbOrderFocus = NULL;
      fLetoDbSeek = NULL;
      fLetoDbRecLock = NULL;
      fLetoDbRecUnLock = NULL;
      fLetoDbIsRecLocked = NULL;
      fLetoDbDelete = NULL;
      fLetoDbRecall = NULL;

      iBufLen = 0;
      free( pBuffer );
   }
}

void leto_Exit( unsigned int uiFull )
{
   fLetoExit( uiFull );
}

unsigned long  leto_ConnnectionNew( const char * szAddr, int iPort )
{
   return (unsigned long )fLetoConnectionNew( szAddr, iPort, NULL, NULL, 0 );
}

void leto_ConnectionClose( unsigned long  pconn )
{
   if( !fLetoConnectionClose )
#if defined( _OS_WIN )
      fLetoConnectionClose = ( LPLetoConnectionClose ) GetProcAddress( hLeto, "_LetoConnectionClose" );
#else
      fLetoConnectionClose = ( LPLetoConnectionClose ) dlsym( hLeto, "LetoConnectionClose" );
#endif
   return fLetoConnectionClose( (LETOCONNECTION *)pconn );
}

char * leto_GetServerVer( unsigned long  pconn )
{
   if( !fLetoGetServerVer )
#if defined( _OS_WIN )
      fLetoGetServerVer = ( LPLetoGetServerVer ) GetProcAddress( hLeto, "_LetoGetServerVer" );
#else
      fLetoGetServerVer = ( LPLetoGetServerVer ) dlsym( hLeto, "LetoGetServerVer" );
#endif
   return fLetoGetServerVer( (LETOCONNECTION *)pconn );
}

unsigned long leto_DbCreateTable( unsigned long pConnection, char * szFile, char * szAlias, char * szFields, unsigned int uiArea )
{
   if( !fLetoDbCreateTable )
#if defined( _OS_WIN )
      fLetoDbCreateTable = ( LPLetoDbCreateTable ) GetProcAddress( hLeto, "_LetoDbCreateTable" );
#else
      fLetoDbCreateTable = ( LPLetoDbCreateTable ) dlsym( hLeto, "LetoDbCreateTable" );
#endif
   return (unsigned long)fLetoDbCreateTable( (LETOCONNECTION *) pConnection, szFile, szAlias, szFields, uiArea );
}

unsigned long leto_DbOpenTable( unsigned long pConnection, char * szFile, char * szAlias, int iShared, int iReadOnly, char * szCdp, unsigned int uiArea, char * szDataFileName, unsigned int uiDFNLen )
{
   return (unsigned long)fLetoDbOpenTable( (LETOCONNECTION *)pConnection, szFile, szAlias, iShared, iReadOnly, szCdp, uiArea, szDataFileName, uiDFNLen );
}

void leto_DbCloseTable( unsigned long pTable )
{
   fLetoDbCloseTable( (LETOTABLE *)pTable );
}

unsigned int leto_DbBof( unsigned long pTable )
{
   return fLetoDbBof( (LETOTABLE *)pTable );
}

unsigned int leto_DbEof( unsigned long pTable )
{
   return fLetoDbEof( (LETOTABLE *)pTable );
}

unsigned int leto_DbFound( unsigned long pTable )
{
   return ((LETOTABLE *)pTable )->fFound;
}

unsigned long leto_DbRecCount( unsigned long pTable )
{
   unsigned long ulCount = 0;
   fLetoDbRecCount( (LETOTABLE *)pTable, &ulCount );
   return ulCount;
}

void leto_DbGoTop( unsigned long pTable, char * szTag )
{
   fLetoDbGoTop( (LETOTABLE *)pTable, szTag );
}

void leto_DbGoBottom( unsigned long pTable, char * szTag )
{
   fLetoDbGoBottom( (LETOTABLE *)pTable, szTag );
}

void leto_DbGoTo( unsigned long pTable, unsigned long ulRecNo, char * szTag )
{
   fLetoDbGoTo( (LETOTABLE *)pTable, ulRecNo, szTag );
}

void leto_DbSkip( unsigned long pTable, long lToSkip, char * szTag )
{
   fLetoDbSkip( (LETOTABLE *)pTable, lToSkip, szTag );
}

unsigned long leto_DbRecNo( unsigned long pTable )
{
   unsigned long ulRecNo = 0;
   fLetoDbRecNo( (LETOTABLE *)pTable, &ulRecNo );
   return ulRecNo;
}

char * leto_DbGetField( unsigned long pTable, unsigned int uiIndex )
{
   unsigned int uiLen = 0;

   fLetoDbFieldLen( (LETOTABLE *)pTable, uiIndex, &uiLen );
   if( uiLen > iBufLen ) {
      iBufLen = uiLen + 1;
      pBuffer = (char*) realloc( pBuffer, iBufLen );
   }
   fLetoDbGetField( (LETOTABLE *)pTable, uiIndex, pBuffer, NULL );
   return pBuffer;
}

void leto_DbPutField( unsigned long pTable, unsigned int uiIndex, char * szValue )
{
   fLetoDbPutField( (LETOTABLE *)pTable, uiIndex, szValue, strlen( szValue ) );
}

void leto_DbAppend( unsigned long pTable )
{

   fLetoDbAppend( (LETOTABLE *)pTable, 1 );
}

void leto_DbPutRecord( unsigned long pTable )
{

   fLetoDbPutRecord( (LETOTABLE *)pTable, 1 );
}

unsigned int leto_DbFieldCount( unsigned long pTable )
{
   unsigned int uiCount = 0;

   if( !fLetoDbFieldCount )
#if defined( _OS_WIN )
      fLetoDbFieldCount = ( LPLetoDbFieldCount ) GetProcAddress( hLeto, "_LetoDbFieldCount" );
#else
      fLetoDbFieldCount = ( LPLetoDbFieldCount ) dlsym( hLeto, "LetoDbFieldCount" );
#endif
   fLetoDbFieldCount( (LETOTABLE *)pTable, &uiCount );
   return uiCount;
}

char * leto_DbFieldName( unsigned long pTable, unsigned int uiIndex )
{
   if( !fLetoDbFieldName )
#if defined( _OS_WIN )
      fLetoDbFieldName = ( LPLetoDbFieldName ) GetProcAddress( hLeto, "_LetoDbFieldName" );
#else
      fLetoDbFieldName = ( LPLetoDbFieldName ) dlsym( hLeto, "LetoDbFieldName" );
#endif
   fLetoDbFieldName( (LETOTABLE *)pTable, uiIndex, pBuffer );
   return pBuffer;
}

unsigned int leto_DbFieldType( unsigned long pTable, unsigned int uiIndex )
{
   unsigned int uiType = 0;

   if( !fLetoDbFieldType )
#if defined( _OS_WIN )
      fLetoDbFieldType = ( LPLetoDbFieldType ) GetProcAddress( hLeto, "_LetoDbFieldType" );
#else
      fLetoDbFieldType = ( LPLetoDbFieldType ) dlsym( hLeto, "LetoDbFieldType" );
#endif

   fLetoDbFieldType( (LETOTABLE *)pTable, uiIndex, &uiType );
   return uiType;
}

unsigned int leto_DbFieldLen( unsigned long pTable, unsigned int uiIndex )
{
   unsigned int uiLen = 0;
   fLetoDbFieldLen( (LETOTABLE *)pTable, uiIndex, &uiLen );
   return uiLen;
}

unsigned int leto_DbFieldDec( unsigned long pTable, unsigned int uiIndex )
{
   unsigned int uiDec = 0;
   fLetoDbFieldDec( (LETOTABLE *)pTable, uiIndex, &uiDec );
   return uiDec;
}

void leto_DbOrderCreate( unsigned long pTable, char * szBagName, char * szTag, char * szKey, unsigned int uiType, unsigned int uiFlags, char * szFor, char * szWhile, unsigned long ulNext )
{

   fLetoDbOrderCreate( (LETOTABLE *) pTable, szBagName, szTag, szKey, ((uiType==2)? 'D' : ((uiType==1)? 'N' : 0)), uiFlags, szFor, szWhile, ulNext );
}

void leto_DbOrderFocus( unsigned long pTable, char * szTagName )
{
   fLetoDbOrderFocus( (LETOTABLE *)pTable, szTagName, 0 );
}

unsigned int leto_DbSeek( unsigned long pTable, char * szTag, const char * szKey, unsigned int bSoftSeek, unsigned int bFindLast )
{
   fLetoDbSeek( (LETOTABLE *)pTable, szTag, szKey, strlen(szKey), bSoftSeek, bFindLast );
   return leto_DbFound( pTable );
}

void leto_DbRecLock( unsigned long pTable, unsigned long ulRecNo )
{
   fLetoDbRecLock( (LETOTABLE *)pTable, ulRecNo );
}

void leto_DbRecUnLock( unsigned long pTable, unsigned long ulRecNo )
{
   fLetoDbRecUnLock( (LETOTABLE *)pTable, ulRecNo );
}

unsigned int leto_DbIsRecLocked( unsigned long pTable, unsigned long ulRecNo )
{
   unsigned int uiRes = 0;
   fLetoDbIsRecLocked( (LETOTABLE *)pTable, ulRecNo, &uiRes );
   return uiRes;
}

void leto_DbDelete( unsigned long pTable )
{
   if( !fLetoDbDelete )
#if defined( _OS_WIN )
      fLetoDbDelete = ( LPLetoDbDelete ) GetProcAddress( hLeto, "_LetoDbDelete" );
#else
      fLetoDbDelete = ( LPLetoDbDelete ) dlsym( hLeto, "LetoDbDelete" );
#endif

   fLetoDbDelete( (LETOTABLE *)pTable );
}

void leto_DbRecall( unsigned long pTable )
{
   if( !fLetoDbRecall )
#if defined( _OS_WIN )
      fLetoDbRecall = ( LPLetoDbRecall ) GetProcAddress( hLeto, "_LetoDbRecall" );
#else
      fLetoDbRecall = ( LPLetoDbRecall ) dlsym( hLeto, "LetoDbRecall" );
#endif

   fLetoDbRecall( (LETOTABLE *)pTable );
}
