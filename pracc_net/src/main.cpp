#include <boost/asio.hpp>
#include <iostream>
#include <string>

namespace asio = boost::asio;
namespace ip = asio::ip;

[[noreturn]] void error(const boost::system::error_code& ec) {
    std::cout << ec.message() << std::endl;
    std::exit(1);
}

void client(const std::string& ipaddr, uint16_t port) {
    asio::io_context ctx;
    ip::tcp::socket soc(ctx);
    boost::system::error_code ec;

    soc.connect(ip::tcp::endpoint(ip::address::from_string(ipaddr), port), ec);

    if(ec) error(ec);

    while(true) {
        std::string buf;
        std::cin >> buf;
        asio::write(soc, asio::buffer(buf), ec);

        if(ec) error(ec);

        if(buf == "end") break;
    }
}

void server(const std::string& ipaddr, uint16_t port) {
    asio::io_context ctx;
    ip::tcp::socket soc(ctx);
    boost::system::error_code ec;

    ip::tcp::acceptor acceptor(
        ctx,
        ip::tcp::endpoint(ip::address::from_string(ipaddr), port));

    acceptor.accept(soc);

    while(true) {
        asio::streambuf buf;
        asio::read(soc, buf, asio::transfer_at_least(1), ec);

        if(ec) error(ec);

        std::cout << asio::buffer_cast<const char*>(buf.data()) << std::endl;
    }
}

// ./a.out [s or c] ipaddr port
int main(int argc, char* argv[]) {
    if(argc != 4) std::exit(1);

    if(strcmp(argv[1], "c")) {
        server(argv[2], std::stoi(argv[3]));
    } else if(strcmp(argv[1], "s")) {
        client(argv[2], std::stoi(argv[3]));
    } else {
        std::exit(1);
    }

    return 0;
}
