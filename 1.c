/****************************************************************************
    > File Name: 1.c
    > Author: TomLyu 
    > Created Time: 2017年06月16日 星期五 17时21分45秒
    > Mail:tomlyu@Ami.com.cn 
    > American Megatrends Information Technology (KunShan) Co., Ltd.
    > Addr:Rm.501,Bldg #3, No.177, Changjiang Middle Rd., Xinduyinzuo, Kunshan, Jiangsu, China, 215301
    > Http://www.ami.com.cn
 ************************************************************************/

#include<stdio.h>

#define MAXLEN_BOOKNAME 10
#define LEN_BOOKID 5


typedef struct bookmessage
{
	char bookname[MAXLEN_BOOKNAME + 1];
	char bookid[LEN_BOOKID + 1];
}Book,*Pbook;

enum ERR_ID 
{
	ERR_SUCCESS = 0,
	ERR_PRASE_IDLEN,
	ERR_PRASE_NAMELEN,
	ERR_PRASE_COLONLACK,
	ERR_PRASE_NAMECHAR,
	ERR_PRASE_IDCHAR
};

//This is a debug message.

const char *err2str(int errcode)
{
	switch(errcode)
	{
		case 0:
			return "success!";
		case 1: 
			return "length of  book id should equal to 5";
		case 2:
			return "length of book name should be (0,9]";
		case 3:
			return "lack of colon";
		case 4:
			return "book name should be consist of char between 'a' and 'z'";
		case 5:
			return "book id should be consist of char between '0' and '9'";
		default: 
			return "unknow error!";
	}
}




int parse(char *p_src,Pbook bookinfo)
{
	int ret_val = ERR_SUCCESS;
	char *p_dest;
	int len;

#if 0
	if (argc <2)
	{
		printf("usage: %s book-name: book-id\n",argv[0]);
		return -1;
	}
#endif	
	printf("p_src :%s\n",p_src);
	//p_src = argv;
	p_dest = bookinfo->bookname;
	len = 0;
	while (*p_src != '\0')
	{
		if (len == MAXLEN_BOOKNAME)
		{
			ret_val = ERR_PRASE_NAMELEN;
			break;
		}

		if (*p_src == ':')
		{

			break;
		}
		
		if (*p_src < 'a' || *p_src > 'z')
		{
			ret_val = ERR_PRASE_NAMECHAR;
			break;
		}

		printf("name len is %d;\n",len);
		printf("%c\n",*p_src);
		*p_dest = *p_src;//error
		p_dest++;
		p_src++;
		len ++;
		printf("name len is %d;\n",len);
	}	

	if(ret_val != ERR_SUCCESS) goto _ERR_EXIT;
	
	if (':' != *p_src) ret_val = ERR_PRASE_COLONLACK;

	if (len == 0 ) ret_val = ERR_PRASE_NAMELEN;
	
	if(ret_val != ERR_SUCCESS) goto _ERR_EXIT;

	
	*p_dest = '\0';
	p_dest = bookinfo->bookid;
	p_src++;
	len = 0;
	printf("name is ready!\n");

	while(*p_src != '\0')
	{
		if(len == LEN_BOOKID)
		{
			ret_val = ERR_PRASE_IDLEN;
			break;
		}
		
		if(*p_src < '0' || *p_src > '9')
		{
			ret_val = ERR_PRASE_IDCHAR;
			break;
		}




		*p_dest++ = *p_src++;
		len++;
	}

	if(ret_val != ERR_SUCCESS) goto _ERR_EXIT;
	
	if(len != LEN_BOOKID) ret_val =  ERR_PRASE_IDLEN;

	p_dest = '\0';



_ERR_EXIT:
	printf("exit_code:%s\n",err2str(ret_val));

	if (ret_val == ERR_SUCCESS)
		printf("after parse, name = %s,id = %s\n",bookinfo -> bookname,bookinfo -> bookid);
	return ret_val;
}




int main(int argc,char* argv[])
{
#if 0
	char bookname[MAXLEN_BOOKNAME + 1] = {0};
	char bookid[LEN_BOOKID + 1] = {0};
#endif
	
	Pbook book;
	if(argc < 2)
	{
		printf("USAGE: ./%s BookName:Bookid\n",argv[0]);
		return -1;
	}
#if 1
	if((parse(argv[1],book)) != 0)
	{

		printf("error\n ");
		return -1;
	}
#endif 
	printf("hello,world\n");
	printf("after parse1111, name = %s,id = %s\n",book->bookname,book->bookid);
	printf("this is master version2.\n");
	return 0;
} 
