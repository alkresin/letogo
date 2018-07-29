package letoGo

/*
#include <stdlib.h>
#include <string.h>
#include <cletocl.h>
int leto_LoadLib( void );
void leto_UnLoadLib( void );
void leto_Exit( unsigned int );
unsigned long leto_ConnnectionNew( const char *, int iPort );
void leto_ConnectionClose( unsigned long  pconn );
char * leto_GetServerVer( unsigned long pconn );
unsigned long leto_DbCreateTable( unsigned long pConnection, char * szFile, char * szAlias, char * szFields, unsigned int uiArea );
unsigned long leto_DbOpenTable( unsigned long pConn, char * szFile, char * szAlias, int iShared, int iReadOnly, char * szCdp, unsigned int uiArea, char * szDataFileName, unsigned int uiDFNLen );
void leto_DbCloseTable( unsigned long pTable );
void leto_CloseAll( unsigned long pConnection );
unsigned int leto_DbBof( unsigned long pTable );
unsigned int leto_DbEof( unsigned long pTable );
unsigned int leto_DbFound( unsigned long pTable );
unsigned long leto_DbRecCount( unsigned long );
void leto_DbGoTop( unsigned long pTable, char * szTag );
void leto_DbGoBottom( unsigned long pTable, char * szTag );
void leto_DbGoTo( unsigned long pTable, unsigned long ulRecNo, char * szTag );
void leto_DbSkip( unsigned long pTable, long lToSkip, char * szTag );
unsigned long leto_DbRecNo( unsigned long pTable );
char * leto_DbGetField( unsigned long pTable, unsigned int uiIndex );
void leto_DbPutField( unsigned long pTable, unsigned int uiIndex, char * szValue );
void leto_DbAppend( unsigned long pTable );
void leto_DbPutRecord( unsigned long pTable );
unsigned int leto_DbFieldCount( unsigned long pTable );
char * leto_DbFieldName( unsigned long pTable, unsigned int uiIndex );
unsigned int leto_DbFieldType( unsigned long pTable, unsigned int uiIndex );
unsigned int leto_DbFieldLen( unsigned long pTable, unsigned int uiIndex );
unsigned int leto_DbFieldDec( unsigned long pTable, unsigned int uiIndex );
void leto_DbOrderCreate( unsigned long pTable, char * szBagName, char * szTag, char * szKey, unsigned char bType, unsigned int uiFlags, char * szFor, char * szWhile, unsigned long ulNext );
void leto_DbOrderFocus( unsigned long pTable, char * szTagName );
unsigned int leto_DbSeek( unsigned long pTable, char * szTag, const char * szKey, unsigned int bSoftSeek, unsigned int bFindLast );
void leto_DbRecLock( unsigned long pTable, unsigned long ulRecNo );
void leto_DbRecUnLock( unsigned long pTable, unsigned long ulRecNo );
unsigned int leto_DbIsRecLocked( unsigned long pTable, unsigned long ulRecNo );
void leto_DbDelete( unsigned long pTable );
void leto_DbRecall( unsigned long pTable );
unsigned int leto_Ping( unsigned long  pconn );
*/
import "C"
import "unsafe"
import "fmt"
import "strconv"

func Init() int8 {
	if C.leto_LoadLib() == 0 {
		fmt.Println("Dynamic library is not loaded\r\n")
		return 0
	}
	return 1
}

func Exit() {
	C.leto_Exit(1)
	C.leto_UnLoadLib()
}

func Connect(sAddr string, iPort int) uint64 {

	var pconn uint64

	csAddr := C.CString(sAddr)
	pconn = (uint64)(C.leto_ConnnectionNew(csAddr, C.int(iPort)))
	C.free(unsafe.Pointer(csAddr))
	return pconn
}

func DisConnect(pconn uint64) {

	C.leto_ConnectionClose((_Ctype_ulong)(pconn))
}

func CreateTable(pconn uint64, sTable string, sAlias string, sFields string, uiArea uint) uint64 {

	var pt uint64

	csTable := C.CString(sTable)
	csAls := C.CString(sAlias)
	csFields := C.CString(sFields)
	pt = (uint64)(C.leto_DbCreateTable((_Ctype_ulong)(pconn), csTable, csAls, csFields, (_Ctype_uint)(uiArea)))
	C.free(unsafe.Pointer(csTable))
	C.free(unsafe.Pointer(csAls))
	C.free(unsafe.Pointer(csFields))

	return pt
}

func OpenTable(pconn uint64, sTable string, sAlias string, bShared bool, bRdOnly bool) uint64 {

	var pt uint64
	var iShared, iRdOnly _Ctype_int

	if bShared {
		iShared = 1
	} else {
		iShared = 1
	}
	if bRdOnly {
		iRdOnly = 1
	} else {
		iRdOnly = 1
	}

	csTable := C.CString(sTable)
	csAls := C.CString(sAlias)
	cscdp := C.CString("")
	pt = (uint64)(C.leto_DbOpenTable((_Ctype_ulong)(pconn), csTable, csAls, iShared, iRdOnly, cscdp, 0, csTable, 0))
	C.free(unsafe.Pointer(csTable))
	C.free(unsafe.Pointer(csAls))
	C.free(unsafe.Pointer(cscdp))

	return pt
}

func CloseTable(pt uint64) {

	C.leto_DbCloseTable((_Ctype_ulong)(pt))
}

func CloseAll(pconn uint64) {

	C.leto_CloseAll((_Ctype_ulong)(pconn))
}

func GetServerVer(pconn uint64) string {

	return C.GoString(C.leto_GetServerVer((_Ctype_ulong)(pconn)))
}

func Bof(pt uint64) bool {

	uiBof := (uint)(C.leto_DbBof((_Ctype_ulong)(pt)))
	if uiBof == 0 {
		return false
	} else {
		return true
	}
}

func Eof(pt uint64) bool {

	uiEof := (uint)(C.leto_DbEof((_Ctype_ulong)(pt)))
	if uiEof == 0 {
		return false
	} else {
		return true
	}
}

func Found(pt uint64) bool {

	uiFound := (uint)(C.leto_DbFound((_Ctype_ulong)(pt)))
	if uiFound == 0 {
		return false
	} else {
		return true
	}
}

func RecCount(pt uint64) uint32 {

	return (uint32)(C.leto_DbRecCount((_Ctype_ulong)(pt)))
}

func GoTop(pt uint64, sTag string) {

	var csTag *_Ctype_char

	if sTag != "" {
		csTag = C.CString(sTag)
	}
	C.leto_DbGoTop((_Ctype_ulong)(pt), csTag)
	if sTag != "" {
		C.free(unsafe.Pointer(csTag))
	}
}

func GoBottom(pt uint64, sTag string) {

	var csTag *_Ctype_char

	if sTag != "" {
		csTag = C.CString(sTag)
	}
	C.leto_DbGoBottom((_Ctype_ulong)(pt), csTag)
	if sTag != "" {
		C.free(unsafe.Pointer(csTag))
	}
}

func GoTo(pt uint64, ulrecno uint32, sTag string) {

	var csTag *_Ctype_char

	if sTag != "" {
		csTag = C.CString(sTag)
	}
	C.leto_DbGoTo((_Ctype_ulong)(pt), (_Ctype_ulong)(ulrecno), csTag)
	if sTag != "" {
		C.free(unsafe.Pointer(csTag))
	}
}

func Skip(pt uint64, lToSkip int32, sTag string) {

	var csTag *_Ctype_char

	if sTag != "" {
		csTag = C.CString(sTag)
	}
	C.leto_DbSkip((_Ctype_ulong)(pt), (_Ctype_long)(lToSkip), csTag)
	if sTag != "" {
		C.free(unsafe.Pointer(csTag))
	}
}

func RecNo(pt uint64) uint32 {

	return (uint32)(C.leto_DbRecNo((_Ctype_ulong)(pt)))
}

func GetField(pt uint64, uiIndex uint32) []byte {

	var cs *_Ctype_char
	cs = C.leto_DbGetField((_Ctype_ulong)(pt), (_Ctype_uint)(uiIndex))
	ilen := C.strlen(cs)
	return C.GoBytes(unsafe.Pointer(cs), C.int(ilen))
}

func GetFieldInt(pt uint64, uiIndex uint32) int64 {

	var iret int64
	iret, _ = strconv.ParseInt(C.GoString(
		C.leto_DbGetField((_Ctype_ulong)(pt), (_Ctype_uint)(uiIndex))), 10, 32)
	return iret
}

func GetFieldFloat(pt uint64, uiIndex uint32) float64 {

	var fret float64
	fret, _ = strconv.ParseFloat(C.GoString(
		C.leto_DbGetField((_Ctype_ulong)(pt), (_Ctype_uint)(uiIndex))), 64)
	return fret
}

func PutField(pt uint64, uiIndex uint32, sValue []byte) {

	C.leto_DbPutField((_Ctype_ulong)(pt), (_Ctype_uint)(uiIndex), (*C.char)(unsafe.Pointer(&sValue[0])))
}

func Append(pt uint64) {

	C.leto_DbAppend((_Ctype_ulong)(pt))
}

func PutRecord(pt uint64) {

	C.leto_DbPutRecord((_Ctype_ulong)(pt))
}

func FieldCount(pt uint64) uint32 {

	return (uint32)(C.leto_DbFieldCount((_Ctype_ulong)(pt)))
}

func FieldName(pt uint64, uiIndex uint32) string {

	return C.GoString(C.leto_DbFieldName((_Ctype_ulong)(pt), (_Ctype_uint)(uiIndex)))
}

func FieldType(pt uint64, uiIndex uint32) uint32 {

	return (uint32)(C.leto_DbFieldType((_Ctype_ulong)(pt), (_Ctype_uint)(uiIndex)))
}

func FieldLen(pt uint64, uiIndex uint32) uint32 {

	return (uint32)(C.leto_DbFieldLen((_Ctype_ulong)(pt), (_Ctype_uint)(uiIndex)))
}

func FieldDec(pt uint64, uiIndex uint32) uint32 {

	return (uint32)(C.leto_DbFieldDec((_Ctype_ulong)(pt), (_Ctype_uint)(uiIndex)))
}

func SetOrder(pt uint64, sTag string) {
	csTag := C.CString(sTag)
	C.leto_DbOrderFocus((_Ctype_ulong)(pt), csTag)
	C.free(unsafe.Pointer(csTag))
}

func CreateOrder(pt uint64, sTag string, sKey string) {
	var csBag, csFor, csWhile *_Ctype_char

	csTag := C.CString(sTag)
	csKey := C.CString(sKey)

	C.leto_DbOrderCreate((_Ctype_ulong)(pt), csBag, csTag, csKey, 0, 0, csFor, csWhile, 0)

	C.free(unsafe.Pointer(csTag))
	C.free(unsafe.Pointer(csKey))
}

func Seek(pt uint64, sTag string, sKey []byte, uiSoftSeek uint32, uiFindLast uint32) bool {
	csTag := C.CString(sTag)
	uiFound := C.leto_DbSeek((_Ctype_ulong)(pt), csTag,
		(*C.char)(unsafe.Pointer(&sKey[0])), (_Ctype_uint)(uiSoftSeek), (_Ctype_uint)(uiFindLast))
	C.free(unsafe.Pointer(csTag))
	if uiFound == 0 {
		return false
	} else {
		return true
	}
}

func RecLock(pt uint64, ulrecno uint32) bool {

	var uiLocked uint32

	C.leto_DbRecLock((_Ctype_ulong)(pt), (_Ctype_ulong)(ulrecno))
	uiLocked = (uint32)(C.leto_DbIsRecLocked((_Ctype_ulong)(pt), (_Ctype_ulong)(ulrecno)))
	if uiLocked == 0 {
		return false
	} else {
		return true
	}
}

func RecUnLock(pt uint64, ulrecno uint32) {

	C.leto_DbRecUnLock((_Ctype_ulong)(pt), (_Ctype_ulong)(ulrecno))
}

func IsRecLocked(pt uint64, ulrecno uint32) bool {

	var uiLocked uint32

	uiLocked = (uint32)(C.leto_DbIsRecLocked((_Ctype_ulong)(pt), (_Ctype_ulong)(ulrecno)))
	if uiLocked == 0 {
		return false
	} else {
		return true
	}
}

func Delete(pt uint64) {

	C.leto_DbDelete((_Ctype_ulong)(pt))
}

func Recall(pt uint64) {

	C.leto_DbRecall((_Ctype_ulong)(pt))
}

func Ping(pconn uint64) bool {

	if C.leto_Ping( (_Ctype_ulong)(pconn) ) == 1 {
		return true
	} else {
		return false
	}
}
