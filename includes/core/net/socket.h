#pragma once

#include <netdb.h>


namespace core::net {
    /// SUMMARY:
    /// Linux's socket representation.
    /// Close() is called in destructor.
    class Socket {    
    public:
        Socket(const char * ip_addr, const char * port);

        /// SUMMARY:
        /// Creates socket from existing fd. Unsafe. Very
        Socket(int socket_fd);
        ~Socket();

        /// FIXME: This is because I dont know how does
        ///        move semantics works in c++ yet. I like Rust.
        /// SUMMARY: 
        /// Makes Socket's instance invalid, preventint it's destructor
        /// from closing socket. You should call it if you going to
        /// return this instance from function.
        /// EXAMPLE:
        /// core::Socket SomeFunction() {
        ///     auto sock = Socket(...);
        ///     ...
        ///     sock.Devalidate();
        ///     return sock;
        /// }
        void Devalidate();

        inline int socket_fd() const { return socket_fd_; }
        inline const char* port() const { return port_; }
        inline addrinfo* res() { return res_; }

    protected:
        const char * ip_addr_;
        const char * port_;

        addrinfo hints_;
        addrinfo * res_;
        int socket_fd_;
        
        bool created_by_server_socket_ = false;
        bool is_valid_ = true;


    };
} //namespace core::net
