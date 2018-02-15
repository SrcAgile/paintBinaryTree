#include <unistd.h>
#include <errno.h>
#include "fileControl.h"
#include "counter.h"
#include "BinaryTree.h"
#include <string.h>
#include <assert.h>

void generateDotBody(node *root,int recursion_context,int fd){
	if(root){
		char *body=(char *)malloc(sizeof(char)*50);
		char *header=(char *)malloc(sizeof(char)*20);
		snprintf(header,20,"%d[label=\"%d\"];\n",recursion_context,root->data);
		r_write(fd,(void *)header,strlen(header));
		if(root->left){
			int a=getCount();
			snprintf(body,50,"%d -- %d;\n",recursion_context,a);
			//assert(len>50-1);
			r_write(fd,(void *)body,strlen(body));
			generateDotBody(root->left,a,fd);
		}
		if(root->right){
			int b=getCount();
			snprintf(body,50,"%d -- %d;\n",recursion_context,b);
			//assert(len>50-1);//caution for tail '\0'
			r_write(fd,(void *)body,strlen(body));
			generateDotBody(root->right,b,fd);
		}
		free(body);
	}	
}
void generateDot(node *root){
	int fd;
	while(fd=open("binary.dot",WRITE_FLAGS,WRITE_PERMS),fd==-1&&errno==EINTR);
	if(fd==-1)
		return;
	char *head="graph graphname{\nnode[shape=\"ellipse\", color=\"red\", fillcolor=\"yellow\"];\n";
	int head_length=strlen(head);
	r_write(fd,(void *)head,head_length);
	generateDotBody(root,0,fd);
	clearCount();
	char *foot="}";
	int foot_length=strlen(foot);
	r_write(fd,(void *)foot,foot_length);
	close(fd);
}

#ifdef DEBUG
int main(){
	node *root;
	initialTree(&root);
	puts("preOrder:");
	preOrder(root);
	generateDot(root);

	pid_t childpid;
	childpid=fork();
	if(childpid==-1){
		perror("can't create a child process");
		return 1;
	}
	if(childpid==0){
		execl("/usr/bin/dot","dot","-Tpng","binary.dot","-o","binary.png",NULL);
		perror("child failed to execute the command");
	}
	//some wait code will be writed right here.
	return 0;
}

#endif


/*use makeargv
 *code here
	char *command="dot -Tpng binary.dot -o binary.png";
	char *delim=" \t";
	char **myargv;
	childpid=fork();
	if(childpid==-1){
		perror("can't create a child process");
		return 1;
	}
	if(childpid==0){
		if(makeargv(command,delim,&myargv)==-1){
			perror("failed to construct argument array");
		}else{
			execvp(myargv[0],&myargv[0]);
			perror("child failed to execute the command");
		}
		return 1;
	}
 */