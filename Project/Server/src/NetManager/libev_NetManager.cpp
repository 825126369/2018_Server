#include "libev_NetManager.h"
namespace basic {
struct ev_loop *loop=NULL;
int libev_NetManager_Init()
{
	int fd=NetManager::getSingle()->getServerSocketInfo()._fd;
		
	loop = ev_default_loop(0);
	
	ev_io* accept_w=new ev_io;
	ev_io_init(accept_w,libev_accept_cb,fd,EV_READ);	
	//ev_io_set(&accept_w,,EV_READ);
	ev_io_start(loop,accept_w);
	
	ev_run(loop,0);

	NetManager::getSingle()->CloseNet();
	ev_loop_destroy(loop);
	cout<<"libev loop End!!!"<<endl;
	return 0;
}

void libev_accept_cb(struct ev_loop *loop,ev_io *w,int revents)
{
		cout<<"accept_cb begin..."<<endl;
		socket_class* client=new socket_class;
		if(NetManager::getSingle()->NetAcceptClient_NoBlock(*client)==-1)
		{
			return;
		}
		ClientManagerPool::getSingle()->InitClient(client);
		int fd=client->_fd;

		ev_io* receive_w=new ev_io;
		ev_io_init(receive_w,libev_receive_cb,fd,EV_READ);
		//ev_io_set(&receive_w,client->_fd,EV_READ);
		ev_io_start(loop,receive_w);

		ev_io* send_w=new ev_io;
		ev_io_init(send_w,libev_send_cb,fd,EV_WRITE);
		//ev_io_set(&send_w,client->_fd,EV_WRITE);
		ev_io_start(loop,send_w);
		//cout<<"accept_cb end"<<endl;
}
void libev_receive_cb(struct ev_loop *loop,ev_io *w,int revents)
{
		cout<<"receive_cb Page Begin"<<endl;
		int fd=(*w).fd;
		ClientInfoPool* mClient=ClientManagerPool::getSingle()->GetClient(fd);
		if(mClient!=NULL)
		{
			mClient->run();
		}else
		{
			ev_io_stop (loop,w);
			cout<<"stop IO watcher:"<<fd<<endl;	
		}
}
void libev_send_cb(struct ev_loop *loop,ev_io *w,int revents)
{
	//int fd=w->fd;	
	//cout<<"Send cb："<<fd<<endl;		
}


}
