/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 18:57:12 by esoulard          #+#    #+#             */
/*   Updated: 2020/04/24 19:40:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../source/libasm.h"
#include <fcntl.h>
#include <limits.h>

//clang -Wall -Wextra -Werror tests/main.c libasm.a

int main()
{
	int errno_true;
	int errno_ft;
	int ret_true;
	int ret_ft;
	char *brr = NULL;

	//ft_strlen
	printf("\n\n------------ FT STRLEN ------------\n\n");
	printf("'bla' 		true 	%ld\n", strlen("bla"));
	printf("'bla' 		ft 	%ld\n\n", ft_strlen("bla"));
	printf("'blab' 		true 	%ld\n", strlen("blab"));
	printf("'blab' 		ft 	%ld\n\n", ft_strlen("blab"));
	printf("'blabl' 	true 	%ld\n", strlen("blabl"));
	printf("'blabl' 	ft 	%ld\n\n", ft_strlen("blabl"));
	printf("'blabla' 	true 	%ld\n", strlen("blabla"));
	printf("'blabla' 	ft 	%ld\n\n", ft_strlen("blabla"));
	printf("'blablab' 	true 	%ld\n", strlen("blablab"));
	printf("'blablab' 	ft 	%ld\n\n", ft_strlen("blablab"));	
	printf("'' 		true 	%ld\n", strlen(""));
	printf("'' 		ft 	%ld\n\n", ft_strlen(""));
	// SEGFAULT CASES
	//printf("NULL	true   	%ld\n", strlen(brr));
	//printf("NULL	ft 	%ld\n", ft_strlen(brr));

	// //ft_strcpy
	printf("\n\n------------ FT STRCPY ------------\n\n");

	char desta[50];
	char destb[50];
	char lilonea[3];
	char liloneb[3];
	strcpy(desta, "bla");
	printf("*char[50]/'bla' 	true '%s'\n", desta);
	ft_strcpy(destb, "bla");
	printf("*char[50]/'bla' 	ft   '%s'\n\n", destb);
	strcpy(desta, "blab");
	printf("*char[50]/'blab' 	true '%s'\n", desta);
	ft_strcpy(destb, "blab");
	printf("*char[50]/'blab' 	ft   '%s'\n\n", destb);
	strcpy(desta, "blabl");
	printf("*char[50]/'blabl' 	true '%s'\n", desta);
	ft_strcpy(destb, "blabl");
	printf("*char[50]/'blabl' 	ft   '%s'\n\n", destb);
	strcpy(desta, "blabla");
	printf("*char[3]/'blabla' 	true '%s'	[UNDEF]\n", lilonea);
	ft_strcpy(destb, "blabla");
	printf("*char[3]/'blabla' 	ft   '%s'	[UNDEF]\n\n", liloneb);
	strcpy(desta, "");
	printf("*char[50]/'' 		true '%s'\n", desta);
	ft_strcpy(destb, "");
	printf("*char[50]/'' 		ft   '%s'\n\n", destb);
	// SEGFAULT CASES
	//strcpy(brr, brr);
	//printf("NULL/NULL 		true '%s'\n", brr);
	//ft_strcpy(brr, brr);
	//printf("NULL/NULL 		ft   '%s'\n\n", brr);
	//strcpy(destb, brr);
	//printf("*char[50]/NULL true %s\n", destb);
	//ft_strcpy(destb, brr);
	//printf("*char[50]/NULL ft   %s\n", destb);
	// strcpy(brr, "abc");
	// printf("NULL/'abc' true %s\n", destb);
	// ft_strcpy(brr, "abc");
	// printf("NULL/'abc' ft   %s\n", destb);

	//ft_strcmp
	printf("\n\n------------ FT STRCMP ------------\n\n");
	
	printf("'aaa'/'abc'	 true %d\n", strcmp("aaa", "abc"));
	printf("'aaa'/'abc'	 ft   %d\n\n", ft_strcmp("aaa", "abc"));
	printf("'a'/'abc'	 true %d\n", strcmp("a", "abc"));
	printf("'a'/'abc'	 ft   %d\n\n", ft_strcmp("a", "abc"));
	printf("''/'abc'	 true %d\n", strcmp("", "abc"));
	printf("''/'abc'	 ft   %d\n\n", ft_strcmp("", "abc"));		
	printf("'qsdfqsf'/'abc'	 true %d\n", strcmp("qsdfqsf", "abc"));
	printf("'qsdfqsf'/'abc'	 ft   %d\n\n", ft_strcmp("qsdfqsf", "abc"));	
	printf("abc/'abc'	 true %d\n", strcmp("abc", "abc"));
	printf("abc/'abc'	 ft   %d\n\n", ft_strcmp("abc", "abc"));
	//SEGFAULT CASES
	//printf("NULL/NULL	 true %d\n", strcmp(brr, brr));
	//printf("NULL/NULL	 ft   %d\n\n", ft_strcmp(brr, brr));
	//printf("NULL/'abc' true %d\n", strcmp(brr, "abc"));
	//printf("NULL/'abc' ft   %d\n", ft_strcmp(brr, "abc"));
	//printf("'abc'/NULL true %d\n", strcmp("abc", brr));
	//printf("'abc'/NULL ft   %d\n", ft_strcmp("abc", brr));

	//ft_write
	printf("\n\n------------ FT WRITE ------------\n\n");
	int     fd1 = open("tests/1.txt", O_WRONLY);
    int     fd2 = open("tests/2.txt", O_WRONLY);
    ft_write(1, "Writing 2x .txt...\n", strlen("Writing 2x .txt...\n"));
    char    *w1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut in dolor odio. Curabitur porta libero ut libero suscipit pretium. Maecenas gravida, risus a sollicitudin bibendum, est nibh posuere ante, facilisis tempor dolor mi ut nisi. Pellentesque arcu est, sagittis ut posuere quis, egestas sed eros. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Fusce vitae mi mauris. Phasellus in ultricies neque. Etiam vel facilisis ante, dapibus luctus enim. Suspendisse eu fringilla erat. Ut feugiat eleifend ipsum, vitae commodo quam cursus nec. Nulla sed accumsan mi, sit amet malesuada lorem. Nunc vitae eleifend elit. ";
    char    *w2 = "";
    ft_write(fd1, w1, strlen(w1));
    ft_write(fd2, w2, strlen(w2));
    close(fd1);
    close(fd2);
	printf("1/'bla'/2 	true %d\n", (int)write(1, "bla", 2));
	printf("1/'bla'/2 	ft   %d\n\n", (int)ft_write(1, "bla", 2));
	printf("1/'bla'/0 	true %d\n", (int)write(1, "bla", 0));
	printf("1/'bla'/0 	ft   %d\n\n", (int)ft_write(1, "bla", 0));
	printf("1/'bla'/6 	true %d\n", (int)write(1, "bla", 6));
	printf("1/'bla'/6 	ft   %d\n\n", (int)ft_write(1, "bla", 6));
	printf("1/''/0 		true %d\n", (int)write(1, "", 0));
	printf("1/''/0 		ft   %d\n\n", (int)ft_write(1, "", 0));
	printf("2/'bla'/3 	true %d\n", (int)write(2, "bla", 3));
	printf("2/'bla'/3 	ft   %d\n\n", (int)ft_write(2, "bla", 3));
	printf("0/'bla'/3 	true %d\n", (int)write(0, "bla", 3));
	printf("0/'bla'/3 	ft   %d\n\n", (int)ft_write(0, "bla", 3));
	//ERROR CASES
	ret_true = (int)write(1, "bla", -2);
	errno_true = errno;
	printf("1/'bla'/-2 		true %d\n", ret_true);
	printf("					errno %d\n", errno_true);
	ret_ft = (int)ft_write(1, "bla", -2);
	errno_ft = errno;
	printf("1/'bla'/-2 		ft   %d\n", ret_ft);
	printf("					errno %d\n\n", errno_ft);
	ret_true = (int)write(1, brr, 6);
	errno_true = errno;
	printf("1/NULL/6 		true %d\n", ret_true);
	printf("					errno %d\n", errno_true);
	ret_ft = (int)ft_write(1, brr, 6);
	errno_ft = errno;
	printf("1/NULL/6 		ft   %d\n", ret_ft);
	printf("					errno %d\n\n", errno_ft);
	ret_true = (int)write(-1, brr, 2);
	errno_true = errno;
	printf("-1/NULL/2 		true %d\n", ret_true);
	printf("					errno %d\n", errno_true);
	ret_ft = (int)ft_write(-1, brr, 2);
	errno_ft = errno;
	printf("-1/NULL/2 		ft   %d\n", ret_ft);
	printf("					errno %d\n\n", errno_ft);
	ret_true = (int)write(-456787, "bla", 3);
	errno_true = errno;
	printf("-456787/'bla'/3 	true %d\n", ret_true);
	printf("					errno %d\n", errno_true);
	ret_ft = (int)write(-456787, "bla", 3);
	errno_ft = errno;
	printf("-456787/'bla'/3 	ft   %d\n", ret_ft);
	printf("					errno %d\n\n", errno_ft);

	//ft read
	printf("\n\n------------ FT READ ------------\n\n");

	int fd;
	int ret;
	char buf[50];
	char bufs[50];
	int i;

	i = -1;
	while(++i < 50)
    {
        buf[i] = 0;
        bufs[i] = 0;
    }
	fd = open("tests/main.c", O_RDONLY);
	ret = read(fd, buf, 30);
	printf("main.c/buf[50]/30		true 	[%d] \n[%s]\n\n", ret, buf);
	close(fd);
	fd = open("tests/main.c", O_RDONLY);
	ret = ft_read(fd, bufs, 30);
	printf("main.c/buf[50]/30		ft 	[%d] \n[%s]\n\n", ret, bufs);
	close(fd);

	i = -1;
	while(++i < 50)
    {
        buf[i] = 0;
        bufs[i] = 0;
    }
	fd = open("tests/main.c", O_RDONLY);
	ret = read(fd, buf, 55);
	errno_true = errno;
	printf("main.c/buf[50]/55	UNDEF	true 	[%d] \n[%s]\n 				errno %d\n", ret, buf, errno_true);
	close(fd);
	fd = open("tests/main.c", O_RDONLY);
	ret = ft_read(fd, bufs, 55);
	errno_ft = errno;
	printf("main.c/buf[50]/55	UNDEF	ft 	[%d] \n[%s]\n 				errno %d\n", ret, bufs, errno_ft);
	close(fd);

	fd = open("tests/main.c", O_RDONLY);
	ret = read(fd, brr, 30);
	errno_true = errno;
	printf("main.c/NULL/80		true 	[%d] \n[%s]\n 			errno %d\n", ret, brr, errno_true);
	close(fd);
	fd = open("tests/main.c", O_RDONLY);
	ret = ft_read(fd, brr, 30);
	errno_ft = errno;
	printf("main.c/NULL/80		ft 	[%d] \n[%s]\n 			errno %d\n", ret, brr, errno_ft);
	close(fd);

	i = -1;
	while(++i < 50)
    {
        buf[i] = 0;
        bufs[i] = 0;
    }
	ret = read(-871, buf, 30);
	errno_true = errno;
	printf("-871/buf[50]/30		true 	[%d] \n[%s]\n 			errno %d\n", ret, buf, errno_true);
	ret = ft_read(-871, bufs, 30);
	errno_ft = errno;
	printf("-871/buf[50]/30		ft 	[%d] \n[%s]\n 			errno %d\n", ret, bufs, errno_ft);


	//ft_strdup
	printf("\n\n------------ FT STRDUP ------------\n\n");

	printf("'bla' 			true '%s'\n", strdup("bla"));
	printf("'bla' 			ft   '%s'\n\n", ft_strdup("bla"));
	printf("'blablablabla' 	true '%s'\n", strdup("blablablabla"));
	printf("'blablablabla' 	ft   '%s'\n\n", ft_strdup("blablablabla"));
	printf("''		 		true '%s'\n", strdup(""));
	printf("''		 		ft   '%s'\n\n", ft_strdup(""));
	//SEGFAULT CASES
	//printf("NULL	 		true '%s'\n", strdup(brr));
	//printf("NULL	 		ft   '%s'\n\n", ft_strdup(brr));
	return(0);
}


