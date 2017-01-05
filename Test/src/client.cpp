#include "ev.h"
#include "common.h"

static void do_connected(struct ev_loop* reactor,ev_io* w,int events)
{
	close(w->fd);
	ev_break(reactor,EVBREAK_ALL);
}

int main()
{
	struct ev_loop* reactor=ev_loop_new(EVFLAG_AUTO);
	int fd=common::new_tcp_client("192.168.1.109",34567);
	ev_io io;
	ev_io_init(&io,&do_connected,fd,EV_WRITE);
	ev_io_start(reactor,&io);
	ev_run(reactor,0);
	close(fd);
	ev_loop_destroy(reactor);
	return 0;
}
