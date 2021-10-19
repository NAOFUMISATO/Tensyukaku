/*****************************************************************//**
 * \file   ResourceServer.h
 * \brief  リソースサーバークラス
 * 
 * \author Sato Naofumi
 * \date   October 2021
 *********************************************************************/
#pragma once
#include   <unordered_map>
/** リソースサーバー */
class ResourceServer {
public:
   static void Init();
   static void Release();

   static void ClearGraph();
   static int LoadGraph(const TCHAR* FileName);
   static int LoadDivGraph(const TCHAR* FileName, int AllNum,
      int XNum, int YNum,
      int XSize, int YSize, int* HandleBuf);

   static int LoadSoundMem(const TCHAR* FileName);

private:
   static std::unordered_map<std::string, int> _mapGraph;
   typedef struct {
      int AllNum;
      int* handle;
   } DIVGRAPH;
   static std::unordered_map<std::string, DIVGRAPH> _mapDivGraph;

   static std::unordered_map<std::string, int> _mapSound;
};

