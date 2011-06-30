﻿#pragma once

#include "SPScrollBar.h"
#include "MCUILayer.h"
#include "../../Model/MCBlockUnit.h"
#include "../../Model/MCDBSource.h"
#include <boost/smart_ptr/shared_ptr.hpp>
#include "TextEdit.h"

class SPMCList
{
public:
  SPMCList();
  ~SPMCList();

  ULMCOpenButton* GetOpenFileBtn();
  SPScrollBar* GetScrollBar();
  CSize GetMCSize();

  void Update(DWORD deltatime);
  void DoPaint(WTL::CDC& dc, RECT& rcclient);
  void HideData();
  void Reload();  // reload current datas
  
  void InitMCList(int w, int h);
  void ReleaseList();

  BOOL ActMouseMove(const POINT& pt);
  BOOL ActMouseLBDown(const POINT& pt);
  BOOL ActMouseLBUp(const POINT& pt);
  BOOL ActWindowChange(int w, int h);
  BOOL ActLButtonDblClick(const POINT& pt);
  BOOL ActRButtonUp(const POINT &pt);
  BOOL ActMouseWheel(UINT nFlags, short zDelta, CPoint point);
  BOOL ActMouseLeave();

private:
  void SetCover();
  void SetMCRect(int w, int h);
  void AddScrollBar();
  void BlocksMouseMove(const POINT& pt);

  void AlignColumns();
  void AlignRows();

private:
  MCDBSource* m_dbsource;
  SPScrollBar* m_sbar;
  CSize m_wndsize;

  BOOL m_listempty;

  BlockUnit* m_selblockunit;

  int m_blockw;
  int m_blockh;

  int m_blockspacing;
  int m_blocktop;
  
  RECT m_wndmargin;

  BOOL m_lockpaint;

  int m_maxrows;
  int m_maxcolumns;

  int m_updaterowpos;

  int m_rowpos;
  int m_columnpos;
  int m_fixcolumnwidth;
  int m_fixrowheight;

  UINT m_maxsbar;
  UINT m_maxoffset;

  float m_anispeed;

  BOOL m_sbardir;

  int m_mousewheelcount;
  BOOL m_mousewheel;

  UINT m_blockcount;

  WTL::CBitmap m_cover;
  CSize m_coversize;

  ULMask* m_ulmask;
  ULMCOpenButton* m_uiopenbtn;
};