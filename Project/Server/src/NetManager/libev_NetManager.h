#ifndef SRC_LIBEV_NETMANAGER_H
#define SRC_LIBEV_NETMANAGER_H
#include "NetManager.h"
#include <ev.h>
using namespace std;
namespace basic
{
int libev_NetManager_Init();
void libev_accept_cb(struct ev_loop *loop,ev_io *w,int revents);
void libev_receive_cb(struct ev_loop *loop,ev_io *w,int revents);
void libev_send_cb(EV_P_ ev_io *w,int revents);
}

#endif
