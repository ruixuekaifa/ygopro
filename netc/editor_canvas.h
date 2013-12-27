#ifndef _EDITOR_CANVAS_H_
#define _EDITOR_CANVAS_H_

#include "wx/wx.h"
#include "wx/glcanvas.h"
#include "deck_data.h"
#include <vector>

namespace ygopro
{
    
    struct TextureInfo;
    
	class wxEditorCanvas : public wxGLCanvas {

	private:
		wxGLContext* glcontext = nullptr;
        wxTimer hover_timer;
		unsigned int glwidth = 0;
		unsigned int glheight = 0;
        TextureInfo* t_buildbg = nullptr;
        TextureInfo* t_deckbg = nullptr;
        TextureInfo* t_font = nullptr;
        TextureInfo* t_hmask = nullptr;
        TextureInfo* t_limits[3] = { nullptr };
        CardTextureInfo* t_draging = nullptr;
        DeckData current_deck;
        short hover_field = 0;
        short hover_index = 0;
        short mouse_field = 0;
        short click_field = 0;
        short click_index = 0;
        unsigned int hover_code = 0;
        unsigned int draging_code = 0;
        wxLongLong click_time = 0;
        double mousex = 0.0;
        double mousey = 0.0;
        
	public:
		wxEditorCanvas(wxFrame* parent, int id, int* args);
		virtual ~wxEditorCanvas();

        DeckData& GetDeck() { return current_deck; }
		void ClearDeck();
        void SaveScreenshot(const wxString& file, bool clipboard = false);
        
        void DrawString(const char* str, int size, unsigned int color, float lx, float ly, float rx, float ry, bool limit);
        void DrawNumber(int number, unsigned int color, float lx, float ly, float rx, float ry);
        void DrawCard(TextureInfo* ti, float lx, float ly, float rx, float ry, bool hl, int limit, float ix, float iy);
		void DrawScene();

		// events
		void EventResized(wxSizeEvent& evt);
		void EventRender(wxPaintEvent& evt);
		void EventMouseMoved(wxMouseEvent& evt);
        void EventMouseLDown(wxMouseEvent& evt);
        void EventMouseLUp(wxMouseEvent& evt);
		void EventMouseLeftWindow(wxMouseEvent& evt);
        void OnHoverTimer(wxTimerEvent& evt);

	};

}

#endif