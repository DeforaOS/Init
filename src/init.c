/* $Id$ */
/* Copyright (c) 2005-2014 Pierre Pronchery <khorben@defora.org> */
/* This file is part of DeforaOS System Init */
/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. */



#include <stdlib.h>
#ifdef DEBUG
# include <stdio.h>
#endif
#include "session.h"
#include "../include/Init.h"
#include "init.h"
#include "../config.h"

#ifndef PREFIX
# define PREFIX		"/usr/local"
#endif
#ifndef SYSCONFDIR
# define SYSCONFDIR	PREFIX "/etc"
#endif


/* Init */
/* private */
/* types */
struct _App
{
	Event * event;
	Session * session;
	AppServer * appserver;

	String * profile;
};


/* public */
/* functions */
/* init_new */
Init * init_new(char const * profile)
{
	Init * init;

#ifdef DEBUG
	fprintf(stderr, "DEBUG: %s(\"%s\")\n", __func__, profile);
#endif
	if((init = object_new(sizeof(*init))) == NULL)
		return NULL;
	init->event = event_new();
	init->session = (init->event != NULL)
		? session_new("Init", profile, init->event) : NULL;
	init->appserver = (init->event != NULL)
		? appserver_new_event(init, 0, "Init", NULL, init->event)
		: NULL;
	init->profile = (profile != NULL) ? string_new(profile) : NULL;
	/* FIXME handle signals (Event class?) */
	/* error handling */
	if(init->event == NULL || init->appserver == NULL
			|| init->profile == NULL)
	{
		init_delete(init);
		return NULL;
	}
	return init;
}


/* init_delete */
void init_delete(Init * init)
{
#ifdef DEBUG
	fprintf(stderr, "DEBUG: %s()\n", __func__);
#endif
	if(init->event != NULL)
		event_delete(init->event);
	object_delete(init);
}


/* AppInterface */
/* init_get_profile */
int Init_get_profile(Init * init, AppServerClient * client, String ** profile)
{
#ifdef DEBUG
	fprintf(stderr, "DEBUG: %s(%p)\n", __func__, (void *)profile);
#endif
	*profile = init->profile;
	return 0;
}


/* init_login */
uint16_t Init_login(Init * init, AppServerClient * client,
		String const * username)
{
#ifdef DEBUG
	fprintf(stderr, "DEBUG: %s(\"%s\")\n", __func__, username);
#endif
	/* FIXME implement */
	return -1;
}


/* init_logout */
uint16_t Init_logout(Init * init, AppServerClient * client)
{
#ifdef DEBUG
	fprintf(stderr, "DEBUG: %s()\n", __func__);
#endif
	/* FIXME implement */
	return -1;
}


/* init_set_profile */
int32_t Init_set_profile(Init * init, AppServerClient * client,
		String const * profile)
{
#ifdef DEBUG
	fprintf(stderr, "DEBUG: %s(\"%s\")\n", __func__, profile);
#endif
	/* FIXME implement */
	return -1;
}


/* useful */
int init_loop(Init * init)
{
#ifdef DEBUG
	fprintf(stderr, "DEBUG: %s()\n", __func__);
#endif
	return event_loop(init->event);
}
