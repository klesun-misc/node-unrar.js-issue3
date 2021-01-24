#include "rar.hpp"

RAROptions::RAROptions()
{
  Init();
}


RAROptions::~RAROptions()
{
  // It is important for security reasons, so we do not have the unnecessary
  // password data left in memory.
  memset(this,0,sizeof(RAROptions));
}


void RAROptions::Init()
{
  memset(this,0,sizeof(RAROptions));
  WinSize=0x2000000;
  Overwrite=OVERWRITE_DEFAULT;
  Method=3;
  MsgStream=MSG_STDOUT;
  ConvertNames=NAMES_ORIGINALCASE;
  xmtime=EXTTIME_HIGH3;
  FileSizeLess=INT64NDF;
  FileSizeMore=INT64NDF;
  HashType=HASH_CRC32;
#ifdef RAR_SMP
  Threads=GetNumberOfThreads();
#endif
#ifdef USE_QOPEN
  // changed from AUTO to NONE by klesun
  // this is probably possible to pass from js somehow without changing the cpp code, but I dunno how
  // changing this to NONE is necessary to skip integrity validation that
  // jumps over all RAR file and fails with READ_ERROR if file is incomplete
  QOpenMode=QOPEN_NONE;
#endif
}
