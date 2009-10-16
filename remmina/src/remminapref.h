/*
 * Remmina - The GTK+ Remote Desktop Client
 * Copyright (C) 2009 - Vic Lee 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, 
 * Boston, MA 02111-1307, USA.
 */
 

#ifndef __REMMINAPREF_H__
#define __REMMINAPREF_H__

/*
 * Remmina Perference Loader
 */

G_BEGIN_DECLS

enum
{
    REMMINA_VIEW_FILE_LIST,
    REMMINA_VIEW_FILE_TREE
};

enum
{
    REMMINA_ACTION_CONNECT = 0,
    REMMINA_ACTION_EDIT = 1
};

enum
{
    AUTO_MODE = 0,
    SCROLLED_WINDOW_MODE = 1,
    FULLSCREEN_MODE = 2,
    SCROLLED_FULLSCREEN_MODE = 3,
    VIEWPORT_FULLSCREEN_MODE = 4
};

enum
{
    REMMINA_TAB_BY_GROUP = 0,
    REMMINA_TAB_BY_PROTOCOL = 1,
    REMMINA_TAB_ALL = 8,
    REMMINA_TAB_NONE = 9
};

typedef struct _RemminaPref
{
    /* In RemminaPrefDialog */
    gboolean save_view_mode;
    gboolean invisible_toolbar;
    gint default_action;
    gint scale_quality;
    gchar *resolutions;
    gint sshtunnel_port;
    gint recent_maximum;
    gint default_mode;
    gint tab_mode;

    gboolean applet_quick_ontop;
    gboolean applet_hide_count;

    /* In View menu */
    gboolean hide_toolbar;
    gboolean hide_statusbar;
    gboolean small_toolbutton;
    gint view_file_mode;

    /* Auto */
    gint main_width;
    gint main_height;
    gboolean main_maximize;
    gint main_sort_column_id;
    gint main_sort_order;

    /* Crypto */
    gchar *secret;
} RemminaPref;

#define DEFAULT_SSHTUNNEL_PORT 4732
#define DEFAULT_SSH_PORT 22

extern const gchar *default_resolutions;
extern gchar *remmina_pref_file;
extern RemminaPref remmina_pref;

void remmina_pref_init (void);
void remmina_pref_save (void);

void remmina_pref_add_recent (const gchar *protocol, const gchar *server);
gchar* remmina_pref_get_recent (const gchar *protocol);
void remmina_pref_clear_recent (void);

guint remmina_pref_keymap_keyval (const gchar *keymap, guint keyval);
gchar* remmina_pref_keymap_groups (void);

G_END_DECLS

#endif  /* __REMMINAPREF_H__  */
