#include "ev.h"
#include "common.h"

void do_accept(struct ev_loop* reactor,ev_io* w,int events)
{
	struct sockaddr_in addr;
	socklen_t addr_size=sizeof(addr);
	int conn=accept(w->fd,(struct sockaddr*)&addr,&addr_size);
	std::string r=common::address_to_string(&addr);
	fprintf(stderr,"accept %s\n",r.c_str());
	close(conn);
}


int main(int length,char** args)
{
	struct ev_loop* reactor=ev_loop_new(EVFLAG_AUTO);
	int fd=common::new_tcp_server(34567);
	ev_io w;
	ev_io_init(&w,do_accept,fd,EV_READ);
	ev_io_start(reactor,&w);
	ev_run(reactor,0);
	close(fd);
	ev_loop_destroy(reactor);
	return 0;
}
