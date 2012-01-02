/*
 ============================================================================
 Name        : Hello.c
 Author      : yixiugg
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <mysql.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char *server = "127.0.0.1";
	char *user = "siteleak";
	char *password = "myleak2011"; /* 此处改成你的密码 */
	char *database = "siteleak";
	conn = mysql_init(NULL);
	/* Connect to database */
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL,
			0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	/* send SQL query */
	if (mysql_query(conn, "show tables")) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	res = mysql_use_result(conn);
	/* output table name */
	printf("MySQL Tables in mysql database:\n");
	while ((row = mysql_fetch_row(res)) != NULL)
		printf("%s \n", row[0]);
	/* close connection */
	mysql_free_result(res);
	mysql_close(conn);
	return EXIT_SUCCESS;
}
