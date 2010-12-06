//---------------------------------------------------------------------------------------
//  This file is part of the Lomse library.
//  Copyright (c) 2010 Lomse project
//
//  Lomse is free software; you can redistribute it and/or modify it under the
//  terms of the GNU General Public License as published by the Free Software Foundation,
//  either version 3 of the License, or (at your option) any later version.
//
//  Lomse is distributed in the hope that it will be useful, but WITHOUT ANY
//  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
//  PARTICULAR PURPOSE.  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with Lomse; if not, see <http://www.gnu.org/licenses/>.
//  
//  For any comment, suggestion or feature request, please contact the manager of
//  the project at cecilios@users.sourceforge.net
//
//--------------------------------------------------------------------------------------

#ifndef __LOMSE_SHAPE_BASE_H__        //to avoid nested includes
#define __LOMSE_SHAPE_BASE_H__

#include "lomse_gm_basic.h"
//#include <vector>
//#include <list>
//#include <sstream>
//using namespace std;

namespace lomse
{

////forward declarations
//class InternalModel;
//class GraphicModel;
//class ImoDocObj;
//class ImoScore;
//class GmoBoxScorePage;
//class GmoBoxSlice;
//class GmoBoxSystem;
//class GmoStubScore;
//class lmStaff;


//---------------------------------------------------------------------------------------


//// global variables
//extern bool g_fDrawSelRect;     //draw selection rectangles around staff objects
//extern bool g_fDrawAnchors;     //draw anchors, to see them in the score
//extern bool g_fDrawBounds;      //draw bounds rectangle
//extern bool g_fShowMargins;     //draw margins in scores, so user can change them
//extern bool g_fFreeMove;		//the shapes can be dragged without restrictions
//extern bool g_fDrawBoundsBoxSystem;         //draw bound rectangles for systems
//extern bool g_fDrawBoundsBoxSlice;          //draw bound rectangles for slices
//extern bool g_fDrawBoundsBoxSliceInstr;     //draw bound rectangles for SliceInstr
//extern bool g_fDrawBoundsShapes;            //draw bound rectangles for non boxes
//
//class lmPaper;
//class lmScoreObj;
//class lmStaffObj;
//class lmInteractor;
//class lmBoxScore;
//class lmBoxPage;
//class lmGMSelection;
//class lmHandler;
//
//class GmoShape;
//class lmBoxSystem;


////level of shape
//enum lmEShapeLevel
//{
//    lm_eMainShape = 0,      //the normal, single shape generated by an ScoreObj
//    lm_eSecondaryShape,     //key and time signatures in system 1 for staves > 1
//    lm_ePrologShape,        //clef and key signatures in systems > 1
//};
//
//#define lmSELECTABLE         true
//#define lmNO_SELECTABLE      false


//---------------------------------------------------------------------------------------
//enum lmEAttachType
//{
//	lm_eGMA_Simple,
//    lm_eGMA_StartObj,
//	lm_eGMA_MiddleObj,
//	lm_eGMA_EndObj,
//};
//
//enum lmEParentEvent
//{
//	lmSHIFT_EVENT = 0,
//	lmMOVE_EVENT,
//};
//
//class lmAttachPoint;



//---------------------------------------------------------------------------------------
class GmoSimpleShape : public GmoShape
{
public:
    virtual ~GmoSimpleShape();

 //   //implementation of virtual methods from base class
 //   virtual wxString Dump(int nIndent) = 0;
 //   virtual void Shift(LUnits xIncr, LUnits yIncr);

 //   //dragging
	//virtual wxBitmap* OnBeginDrag(double rScale, wxDC* pDC) { return (wxBitmap*)NULL; }
 //   virtual UPoint OnDrag(lmPaper* pPaper, const UPoint& uPos) { return uPos; };

protected:
    GmoSimpleShape(GmoObj* owner, int objtype, Color color);
    //GmoSimpleShape(lmEGMOType m_nType, lmScoreObj* pOwner, int nOwnerIdx,
    //              wxString sName=_T("SimpleShape"),
				//  bool fDraggable = true, bool fSelectable = true,
    //              wxColour color = *wxBLACK, bool fVisible = true);

};


//---------------------------------------------------------------------------------------
class GmoCompositeShape : public GmoShape
{
protected:
	//bool					m_fDoingShift;	//semaphore to avoid recomputing constantly the bounds
 //   bool					m_fGrouped;		//its component shapes must be rendered as a single object
	//std::vector<GmoShape*>	m_Components;	//list of its constituent shapes

public:
    virtual ~GmoCompositeShape();

 //   //dealing with components
 //   virtual int Add(GmoShape* pShape);
	//inline int GetNumComponents() const { return (int)m_Components.size(); }
	//virtual void RecomputeBounds();

 //   //virtual methods from base class
 //   virtual wxString Dump(int nIndent);
 //   virtual void Shift(LUnits xIncr, LUnits yIncr);
	//virtual void Render(lmPaper* pPaper, wxColour color);
 //   virtual void RenderHighlighted(wxDC* pDC, wxColour colorC);
 //   virtual void RenderWithHandlers(lmPaper* pPaper);

	////overrides
 //   bool BoundsContainsPoint(UPoint& uPoint);
 //   bool Collision(GmoShape* pShape);
 //   virtual void SetSelected(bool fValue);

 //   //dragging
 //   virtual wxBitmap* OnBeginDrag(double rScale, wxDC* pDC);
 //   virtual UPoint OnDrag(lmPaper* pPaper, const UPoint& uPos);


protected:
    GmoCompositeShape(GmoObj* owner, int objtype, Color color);
    //GmoCompositeShape(lmScoreObj* pOwner, int nOwnerIdx, wxColour color = *wxBLACK,
    //                 wxString sName = _T("CompositeShape"), bool fDraggable = false,
    //                 lmEGMOType nType = eGMO_ShapeComposite, bool fVisible = true);
	//GmoShape* GetShape(int nShape);

};


}   //namespace lomse

#endif    // __LOMSE_SHAPE_BASE_H__

