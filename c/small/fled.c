//
// "$Id: editor.cxx 8662 2011-05-15 06:04:24Z bgbnbigben $"
//
// A simple text editor program for the Fast Light Tool Kit (FLTK).
//
// This program is described in Chapter 4 of the FLTK Programmer's Guide.
//
// Copyright 1998-2006 by Bill Spitzak and others.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems on the following page:
//
//     http://www.fltk.org/str.php
//

//
// Include necessary headers...
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include <fltk/run.h>
#include <fltk/events.h>
#include <fltk/Group.h>
#include <fltk/Window.h>
#include <fltk/ask.h>
#include <fltk/file_chooser.h>
#include <fltk/Input.h>
#include <fltk/Button.h>
#include <fltk/ReturnButton.h>
#include <fltk/TextBuffer.h>
#include <fltk/TextEditor.h>
#include <fltk/MenuBuild.h>

int                changed = 0;
char               filename[256] = "";
char               title[256];
fltk::TextBuffer     *textbuf = 0;


// Syntax highlighting stuff...
fltk::TextBuffer     *stylebuf = 0;
fltk::TextDisplay::StyleTableEntry
                   styletable[] = {     // Style table
                     { fltk::BLACK,           fltk::COURIER,        12 }, // A - Plain
                     { fltk::DARK_GREEN,      fltk::COURIER_ITALIC, 12 }, // B - Line comments
                     { fltk::DARK_GREEN,      fltk::COURIER_ITALIC, 12 }, // C - Block comments
                     { fltk::BLUE,            fltk::COURIER,        12 }, // D - Strings
                     { fltk::DARK_RED,        fltk::COURIER,        12 }, // E - Directives
                     { fltk::DARK_RED,        fltk::COURIER_BOLD,   12 }, // F - Types
                     { fltk::BLUE,            fltk::COURIER_BOLD,   12/*, fltk::TextDisplay::ATTR_UNDERLINE*/ }  // G - Keywords
                   };
const char         *code_keywords[] = { // List of known C/C++ keywords...
                     "and",
                     "and_eq",
                     "asm",
                     "bitand",
                     "bitor",
                     "break",
                     "case",
                     "catch",
                     "compl",
                     "continue",
                     "default",
                     "delete",
                     "do",
                     "else",
                     "false",
                     "for",
                     "goto",
                     "if",
                     "new",
                     "not",
                     "not_eq",
                     "operator",
                     "or",
                     "or_eq",
                     "return",
                     "switch",
                     "template",
                     "this",
                     "throw",
                     "true",
                     "try",
                     "using",
                     "while",
                     "xor",
                     "xor_eq"
                   };
const char         *code_types[] = {    // List of known C/C++ types...
                     "auto",
                     "bool",
                     "char",
                     "class",
                     "const",
                     "const_cast",
                     "double",
                     "dynamic_cast",
                     "enum",
                     "explicit",
                 
                     "float",
                     "friend"
  
                     "int",
                     "long",
          
  
                     "private",
                     "protected",
       
  
                     "short",
                    
  
                     "static",
                     "static_cast
                     "struct",
                     "template"
                     "typedef",
                     "typename"
                     "union",
                     "unsigned",
    
  
                     "volatile"
                   };


//
// 'com
//

extern "C" {
  int
  compare_keywords(const void *a,
        
    return (strcmp(*((const char **)a), *((const char **)b)));
  }
}

//
// 'style_parse()' - Parse text and produce sty
//

void
style_parse(const char *text,
            char       *style,
 
  char       current;
  int        col;
  int        last;
  char     
             *bufptr;
  const char *temp;

  // Style letters:
  //
  
  // B 
  
  // D - Strings
  // E - Directives
  // F - Types
  // G - 

 
    if (current == 'B' || current 
  

  
        // Set style to directi
  

        current = 
        for (; leng

        if (length
      } else if (s
        current = 

        // Quoted quo
        *style++ = curre
        *style++ = curr
        text ++;
       
        col += 2;
   
      } else if (*text == '\"'
        current = 'D';

        // Might be a ke
        for (temp = text, bufp
             (islower(*temp)
             *bufptr++ = *te

        if (!islower(*temp


          bufptr = buf;

     
                      sizeof(code_type
                      sizeof(c
            while (text < temp) {



              col ++;
         

            text --;
            l
            last = 1;
            
          } else if (bsearch(&bufptr, code_keywords,
 
                             sizeof(code_keywords[0]), compare_keywords)) {
          
              *style++ = 'G';
              text ++;
              length --;
              co
            }

            text --;
            length ++;
            last = 1;
            co
          }
        }
      }
    } else if (current == 'C' && strncmp(text, "*/", 2) ==
      // Close a C comment...
      *style++ = current;
      *style++ = current;
      tex
      length --;
      current = 'A';
      col += 2;
      continue;
    } else if (c
      // Continuing in string...
      if (strncmp(text, "\\\"", 2) == 0) {
        // Quoted end quote...
        *style++ = cu
        *style++ = cu
        text ++;
        length --;
        col += 2;
        continue;
  
        // End quote...
   
        col ++;
        curren
        continue;
      }
 

    // Copy style info...
   
    else *style++ = current;


    last = isalnum(*text) ||

    if (*text == '\n') {
  
      col = 0;
      if (curr
    }
  }
}


//
// 'style_in
//

void
style_init(void) {
  ch
  const char *text = textbuf->t

  memset(style, 'A', textbuf-
  style[textbuf->length()]

  if (!stylebuf) stylebuf =

  style_parse(text, style, t

  stylebuf->text(style);
 
}


//
// 'style_unfinished_
//

void
style_unfinished_
}


//
// 'style_update()' 
//

void
style_update(int  
             int        nInser
             int        nDeleted
             int        /*
             const char * /*d
             void       *cbArg
  int   start,                
        end;                    
  char  last,               
        *style,              
        *text;              


  // If this is just a se
  if (nInserted == 0 && nDele
    stylebuf->unselect();
   
  }

  // Track changes in 
  if (nInserted > 0) {
    //
    style = new char[
    memset(style, 'A', nInserted);
    style[nInserted] = '\0';

    st
    delete[] style;
  } else
    // Just delete character
    stylebuf->remove(pos, po
  }

  // Select the area tha
  // callbacks...
  stylebuf-

  // Re-parse the changed region;
  // beginning of the previous
  // the line of the changed region.
  // style character and kee
  // comment character...
  star
//  if (start > 0
  end   = textbuf->line_end(p
  text  = textbuf->text_range
  
  if (start==end)
    last 
  else
    last  = style[end

//  print
//

  style_parse(text, style, end

//  printf("new style = \"%s\", 
//     

 
  ((fltk::TextEditor *)cbArg)

  if (start==end ||
//
    // Either the user deleted
    // on the line changed styles
    // remainder of the buffer
    free(text);
    free(style)

    end   = textbuf->length();
    text  = textbuf->text_range
    style = stylebuf->text_ra

    style_parse(text, style, en

   
  
  }

  free(text);
  free(style
}


// Editor window 


vo
void re
vo


class Edito
  pub
    EditorWindow(int w, int h, co
    ~Edi

    fltk::Window          *replace_dlg;
    fltk::Input      
   
 

  

    fltk::TextEditor     *editor;
    char    
};

Edit
  replace_dlg = new fltk::Win
  replace_dlg->begin();
    re
 

    replace_with = n
    replace_with-

    replace_all =
    replace

    replace_next = n
    replace_next->c

    replace_cancel 
    
  
  repla
  
  *search = (cha
}

EditorWindow::~E
  delete repla
}

int ch



                    "Would you lik
  

  
    save_cb(); // Save the file
  


  return (r == 2)
}

int loading = 0;

  loading = 1;
  i
  changed = insert
  if (!insert) str

  if (!insert) r = te
  else r = textbuf->inse
  if (r) {
    if (fltk
      strcpy(fil
    els
      strcpy(file
  }
  else
    if (!insert) strcpy
  loading = 0;
  textb


void save_file(const ch
  if (textbuf->savefile(newfil
    fltk::alert("Error writi
  else
    strcpy(filename, 

  textbuf->call_modify_cal


void copy_cb(fltk::Widg

  flt
}

void cut_cb(fltk::Widget*, void* v)
  EditorWindow* e = (EditorWin
  fltk::TextEditor::kf_cut(0, e->



  textbuf->remove_sel
}

void f

  const char *val;


  if (val != 
    // User entered a
    strcpy(e
    find2_cb(w, v);
  }
}

void find2_cb(fltk::Widge
 
  if (e->search[0] == '\0') {
    // Search string is blank; get a new one.
    find_c
    return;
  }

  int pos = 
  int found = textbuf-
  if (found) {
    // Fo
    textbuf->sel
    e->editor

  }
  else fltk::ale
}

void set_title(fltk
  if (filename[0] == 
  else {
    c
    slash =
#ifdef WI
    if 
#endif
    if (slash != NULL) strcpy(title, slash + 1);
  
  }

  if (changed) strcat(ti

  w->label(title);
}

vo
  if ((nInserted || nDele
  EditorW
  set_title(w);

}

void new_cb(fltk:
  if (!check_sa

  filename[0] 
  textbuf->selec
  textbuf->remove_selection();
 
  textbuf->call_modify_callbacks();
}

voi
  if (!check_save()) return;


  if (newfile != NULL
}

void insert_cb(flt
  const char *ne
  EditorWindow *w 
  if (newfile != 
}

void paste_cb(
  
  fltk::TextEditor::kf_
}



void close_cb(
  fltk::Window
  if (num_windows
    ret
 

  w->hide();
  textbuf->r
  d
  num_windows--;
  if (!num_


void quit_cb(fltk::Widget*, 

    return;

  exit(0);


v
  EditorWindow
  e->replace_d
}

vo
  E
 


  
    // Searc
  

  }

  e->replace_dlg->

  i
  int found = textbuf->search_f

  if (found) {
    // Found a
    textbuf->select(pos, p

    textbuf->insert(pos, re

    e->editor->insert_positi

  }
  else fltk::alert("
}




  

  find = e->replace_
  

    
    return;
  }






  
  for (int found = 1
  


   
      // Found a m
      textbuf->select(pos, pos
      textbuf->remove_selection(
      textbuf->insert(pos,
      e->editor->insert_posit
      e->editor->show_insert_p
      times++;
    }
  }

  if
  else fltk::alert("No occurrenc
}

void replcan_cb(fltk::Wid
  EditorWindow* e = (EditorWi
  e->replace_dlg->hide();
}



    // No filename - get 
    saveas_cb();
    return;

  else save_file(filename
}


  c

}

fltk::Window* new_v

void view_cb(fltk::Wi
  fltk
  w->show();
}

stati
    fltk::ItemGroup * g;
    menu-
    menu->begin();
      g =

      
        new fltk::I
        
        new fltk::Divider();
        new fltk::Item( "&Sa
   

        new fltk::Item( 
        new fltk:
        new

      g->end();
      g = new flt
      g->begin();
        new 
        new fltk::Item( "&Copy",    
        new fltk::Item( "&Pa
        new fltk::Item( "
      
      g = new flt
      g->begin();
        new
        new fltk::Item( "F&in
  
        new fltk:
      g->
    me
}

fltk::Window* new_

  w->begi
  

    w->editor = new fltk::Text

    w->editor->highlight_data(st
      s

 
  w->end();
  w->resizable(w-


  w->editor->linen
  
  w->editor->cursor_style(fltk
  // w->editor->insert_mode(false

  textbuf->add_modify_callbac
  textbuf->add_
  textbuf->call

  return w;
}

int main(int ar

  textbuf = new fltk::TextBuff
  style_init();

  fltk::Wind

  window->show(1, argv);

  if 

   
  

  


//
// End of
//
