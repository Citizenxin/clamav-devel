/*
 *  Copyright (C) 2002 Nigel Horne <njh@bandsman.co.uk>
 *
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
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef	_MESSAGE_H
#define	_MESSAGE_H

#define	MAXARGS	5	/* maximum number of arguments to a mime content-type */

typedef struct message {
	mime_type	mimeType;
	encoding_type	encodingType;
	char	*mimeSubtype;
	char	*mimeArguments[MAXARGS];
	char	*mimeDispositionType;	/* probably attachment */
	text	*body_first, *body_last;
} message;

message	*messageCreate(void);
void	messageDestroy(message *m);
void	messageReset(message *m);
void	messageSetMimeType(message *m, const char *type);
mime_type	messageGetMimeType(const message *m);
void	messageSetMimeSubtype(message *m, const char *subtype);
const	char	*messageGetMimeSubtype(const message *m);
void	messageSetDispositionType(message *m, const char *disptype);
const	char	*messageGetDispositionType(const message *m);
void	messageAddArgument(message *m, const char *arg);
void	messageAddArguments(message *m, const char *arg);
const	char	*messageFindArgument(const message *m, const char *variable);
void	messageSetEncoding(message *m, const char *enctype);
encoding_type	messageGetEncoding(const message *m);
void	messageAddLine(message *m, const char *line);
const	text	*messageGetBody(const message *m);
void	messageClean(message *m);
blob	*messageToBlob(const message *m);
text	*messageToText(const message *m);

#endif	/*_MESSAGE_H*/
