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
//---------------------------------------------------------------------------------------

#ifndef __LOMSE_GRAPHIC_VIEW_H__
#define __LOMSE_GRAPHIC_VIEW_H__

#include "lomse_injectors.h"
#include "lomse_view.h"
#include "lomse_drawer.h"
#include "lomse_doorway.h"
#include "lomse_agg_types.h"
#include <vector>
using namespace std;


namespace lomse
{

//forward declarations
class Document;
class GraphicModel;
class ScreenDrawer;
class Drawer;
class Presenter;
class Interactor;


//---------------------------------------------------------------------------------------
// A view to edit the score in full page
class GraphicView : public View
{
protected:
    LibraryScope& m_libraryScope;
    GraphicModel* m_pGraficModel;
    ScreenDrawer* m_pDrawer;
    std::vector<RenderingBuffer*> m_pPages;
    LomseDoorway* m_pDoorway;
    RenderOptions m_options;
    RenderingBuffer* m_pRenderBuf;
    //DocCursor       m_cursor;

public:
    GraphicView(LibraryScope& libraryScope, Document* pDoc, Interactor* pInteractor,
                ScreenDrawer* pDrawer);
    virtual ~GraphicView();

    void set_rendering_buffer(RenderingBuffer* rbuf) { m_pRenderBuf = rbuf; }
    //--------------------------------------------------------------------
    // Methods to serve platform dependent event handlers. 
    //virtual void on_init();
    virtual void on_resize(Pixels x, Pixels y);
    //virtual void on_idle();
    virtual void on_mouse_move(Pixels x, Pixels y, unsigned flags);
    virtual void on_mouse_button_down(Pixels x, Pixels y, unsigned flags);
    virtual void on_mouse_button_up(Pixels x, Pixels y, unsigned flags);
    //virtual void on_key(Pixels x, Pixels y, unsigned key, unsigned flags);
    //virtual void on_ctrl_change();

    //--------------------------------------------------------------------
    // The View is requested to re-paint itself onto the window
    virtual void on_paint();
    //virtual void on_post_draw(void* raw_handler);

    //window related commands
    void update_window();

    //inline DocCursor& get_cursor() { return m_cursor; }
    void on_document_reloaded();

    ////caret movement
    //void caret_right();
    //void caret_left();
    //void caret_to_object(long nId);

    //observed object notifications
	void handle_event(Observable* ref);

    //graphic model
    GraphicModel* get_graphic_model();

    //scale
    void zoom_in(Pixels x=0, Pixels y=0);
    void zoom_out(Pixels x=0, Pixels y=0);
    void set_scale(double scale, Pixels x=0, Pixels y=0);
    double get_scale();

    //rendering options
    inline void set_option_draw_box_doc_page_content(bool value) { 
        m_options.draw_box_doc_page_content_flag = value;
    }
    inline void set_option_draw_box_score_page(bool value) { 
        m_options.draw_box_score_page_flag = value; 
    }
    inline void set_option_draw_box_system(bool value) { 
        m_options.draw_box_system_flag = value; 
    }
    inline void set_option_draw_box_slice(bool value) {
        m_options.draw_box_slice_flag = value; 
    }
    inline void set_option_draw_box_slice_instr(bool value) { 
        m_options.draw_box_slice_instr_flag = value; 
    }

protected:
    GraphicModel* create_graphic_model();
    void draw_graphic_model();
    void add_controls();
    virtual void generate_paths() = 0;

    //renderization parameters
    double m_expand;
    double m_gamma;
    double m_rotation;
    TransAffine m_transform;


    ////agg renderization related 
    //agg::slider_ctrl<agg::rgba8> m_expand;
    //agg::slider_ctrl<agg::rgba8> m_gamma;
    //agg::slider_ctrl<agg::rgba8> m_scale;
    //agg::slider_ctrl<agg::rgba8> m_rotate;

    //current viewport origin (pixels)
    Pixels m_vxOrg;      
    Pixels m_vyOrg;

    //temporary for dragging (pixels)
    Pixels m_dx;        
    Pixels m_dy;
    bool   m_drag_flag;
};


//---------------------------------------------------------------------------------------
// A graphic view with one page, no margins (i.e. LenMus ScoreAuxCtrol)
class LOMSE_EXPORT SimpleView : public GraphicView
{
protected:

public:
    SimpleView(LibraryScope& libraryScope, Document* pDoc, 
               Interactor* pInteractor, ScreenDrawer* pDrawer);
    virtual ~SimpleView() {}

protected:
    void generate_paths();

};


//---------------------------------------------------------------------------------------
// A graphic view with pages in vertical (i.e. Adobe PDF Reader, MS Word)
class LOMSE_EXPORT VerticalBookView : public GraphicView
{
protected:

public:
    VerticalBookView(LibraryScope& libraryScope, Document* pDoc, 
                     Interactor* pInteractor, ScreenDrawer* pDrawer);
    virtual ~VerticalBookView() {}

protected:
    void generate_paths();

};


//---------------------------------------------------------------------------------------
// A graphic view with pages in horizontall (i.e. Finale, Sibelius)
class LOMSE_EXPORT HorizontalBookView : public GraphicView
{
protected:

public:
    HorizontalBookView(LibraryScope& libraryScope, Document* pDoc,
                       Interactor* pInteractor, ScreenDrawer* pDrawer);
    virtual ~HorizontalBookView() {}

protected:
    void generate_paths();

};



}   //namespace lomse

#endif      //__LOMSE_GRAPHIC_VIEW_H__
