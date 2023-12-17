#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/util.h>

void http_request_handler(struct evhttp_request *req, void *arg) {
    struct evbuffer *buf = evbuffer_new();
    if (!buf) {
        puts("Failed to create response buffer");
        return;
    }

    evbuffer_add_printf(buf, "Hello, world!");
    evhttp_send_reply(req, HTTP_OK, "OK", buf);

    evbuffer_free(buf);
}

int main() {
    struct event_base *base;
    struct evhttp *http;
    struct evhttp_bound_socket *handle;

    base = event_base_new();
    if (!base) {
        puts("Failed to create event base");
        return 1;
    }

    http = evhttp_new(base);
    if (!http) {
        puts("Failed to create HTTP server");
        return 1;
    }

    evhttp_set_gencb(http, http_request_handler, NULL);

    handle = evhttp_bind_socket_with_handle(http, "0.0.0.0", 8080);
    if (!handle) {
        puts("Failed to bind to port");
        return 1;
    }

    event_base_dispatch(base);

    return 0;
}
