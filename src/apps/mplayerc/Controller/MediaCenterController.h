﻿#pragma once

#include "LazyInstance.h"
#include "../Model/MediaComm.h"
#include "../Model/MediaModel.h"
#include "../Model/MediaTreeModel.h"
#include "MediaCheckDB.h"
#include "MediaSpiderFolderTree.h"
#include <map>
#include "..\UserInterface\Renderer\BlockList.h"
#include "CoverDownloadController.h"
#include "CoverUploadController.h"
#include "LoadMediaDataFromDB.h"

class MediaCenterController:
  public LazyInstanceImpl<MediaCenterController>
{
public:
  MediaCenterController();
  ~MediaCenterController();

public:
  // Maintenance for MC folder
  static bool IsMCFolderExist();
  static void CreateMCFolder();

public:
  // Gui control, should not for other use

   void UpdateBlock(RECT rc);
   void DelBlock(int i);

   void SetFrame(HWND hwnd);

   void Playback(std::wstring file);

   BOOL GetPlaneState();

   void SetPlaneState(BOOL bl);

   BlockListView& GetBlockListView();

   HRGN CalculateUpdateRgn(WTL::CRect& rc);

   void SetCover(BlockUnit* unit, std::wstring orgpath);

// slots
public:
  void HandlePlayback(const MediaData &md);

  void HandleDelBlock(const BlockUnit *pBlock);

public:
  // Data control
  void SpiderStart();
  void SpiderStop();

  void LoadMediaData(int direction, std::list<BlockUnit*>* list, int viewcapacity, 
                     int listcapacity, int remain, int times = 1);
  
  HANDLE GetMediaDataThreadHandle();

  BOOL LoadMediaDataAlive();
  
private:
  // GUI
  HWND m_hwnd;
  BOOL m_planestate;
  
  BlockListView m_blocklist;
  CoverDownloadController m_coverdown;
  CoverUploadController m_coverup;
  BOOL m_initiablocklist;
  LoadMediaDataFromDB m_loaddata;
  
  // Data
  MediaModel            m_model;
  media_tree::model     m_treeModel;
  MediaSpiderFolderTree m_spider;
};