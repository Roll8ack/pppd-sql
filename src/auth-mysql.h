/*
 *  auth-mysql.h -- Challenge Handshake Authentication Protocol and Password
 *                  Authentication Protocol for the Point-to-Point Protocol
 *                  (PPP) via MySQL.
 *
 *  Copyright (c) 2008 Maik Broemme <mbroemme@plusserver.de>
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
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _AUTH_MYSQL_H
#define _AUTH_MYSQL_H

/* client ip address must be stored in global variable, because at IPCP time
 * we no longer know the username.
 */
extern uint32_t client_ip;

/* this function handles the mysql_error() result. */
int32_t pppd__mysql_error(
	uint32_t	error_code,
	const uint8_t	*error_message,
	const uint8_t	*error_state
);

/* this function check the chap authentication information against a mysql database. */
int32_t pppd__chap_verify_mysql(
	char		*name,
	char		*ourname,
	int		id,
	struct chap_digest_type		*digest,
	unsigned char	*challenge,
	unsigned char	*response,
	char		*message,
	int		message_space
);

/* this function check the pap authentication information against a mysql database. */
int32_t pppd__pap_auth_mysql(
	char		*user,
	char		*passwd,
	char		**msgp,
	struct wordlist	**paddrs,
	struct wordlist	**popts
);

#endif					/* _AUTH_MYSQL_H */