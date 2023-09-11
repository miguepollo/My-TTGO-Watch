/****************************************************************************
 *   Aug 21 17:26:00 2020
 *   Copyright  2020  Chris McNamee
 *   Email: chris.mcna@gmail.com
 ****************************************************************************/
 
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#include "config.h"

#include "stopwatch_app.h"
#include "stopwatch_app_main.h"

#include "gui/mainbar/mainbar.h"
#include "gui/statusbar.h"
#include "gui/app.h"
#include "gui/widget.h"

#ifdef NATIVE_64BIT
    #include "utils/logging.h"
    #include "utils/millis.h"
#else
    #include <Arduino.h>
#endif
/*
 * app tile number
 */
uint32_t stopwatch_app_main_tile_num;
/*
 * app and widget icon
 */
icon_t *stopwatch_app = NULL;
icon_t *stopwatch_widget = NULL;
/*
 * declare you images or fonts you need
 */
LV_IMG_DECLARE(stopwatch_app_64px);
/*
 * declare callback functions
 */
static void enter_stopwatch_app_event_cb( lv_obj_t * obj, lv_event_t event );
/*
 * automatic register the app setup function with explicit call in main.cpp
 */
static int registed = app_autocall_function( &stopwatch_app_setup, 1 );           /** @brief app autocall function */
/*
 * setup routine for stopwatch app
 */
void stopwatch_app_setup( void ) {
    /*
     * check if app already registered for autocall
     */
    if( !registed ) {
        return;
    }
    /*
     * register app icon on the app tile
     */
    stopwatch_app_main_tile_num = mainbar_add_app_tile( 1, 1, "Stopwatch App" );
    stopwatch_app = app_register( "stop\nwatch", &stopwatch_app_64px, enter_stopwatch_app_event_cb );
    stopwatch_app_main_setup( stopwatch_app_main_tile_num );
}
/**
 * @brief get the app tile number
 * 
 * @return uint32_t 
 */
uint32_t stopwatch_app_get_app_main_tile_num( void ) {
    return( stopwatch_app_main_tile_num );
}
/**
 * @brief callback function to enter the app
 * 
 * @param obj           pointer to the object
 * @param event         the event
 */
static void enter_stopwatch_app_event_cb( lv_obj_t * obj, lv_event_t event ) {
    switch( event ) {
        case( LV_EVENT_CLICKED ):       stopwatch_app_hide_app_icon_info( true );
                                        mainbar_jump_to_tilenumber( stopwatch_app_main_tile_num, LV_ANIM_OFF, true );
                                        break;
    }    
}
/**
 * @brief add the widget to the mainbar
 */
void stopwatch_add_widget( void ) {
    stopwatch_widget = widget_register( "stopwatch", &stopwatch_app_64px, enter_stopwatch_app_event_cb );
}
/**
 * @brief remove the widget from the mainbar
 */
void stopwatch_remove_widget( void ) {
    stopwatch_widget = widget_remove( stopwatch_widget );
}
/**
 * @brief update widget label
 * 
 * @param label         text to display
 */
void stopwatch_app_update_widget_label( char *label ) {
    widget_set_label( stopwatch_widget, label );
}
/**
 * @brief hide or show the app icon info
 * 
 * @param show 
 */
void stopwatch_app_hide_app_icon_info( bool show ) {
    if ( !show ) {
        app_set_indicator( stopwatch_app, ICON_INDICATOR_1 );
    }
    else {
        app_hide_indicator( stopwatch_app );
    }
}
/**
 * @brief hide or show the widget icon info
 * 
 * @param show 
 */
void stopwatch_app_hide_widget_icon_info( bool show ) {
    if ( !show ) {
        widget_set_indicator( stopwatch_widget, ICON_INDICATOR_1 );
    }
    else {
        widget_hide_indicator( stopwatch_widget );
    }
}