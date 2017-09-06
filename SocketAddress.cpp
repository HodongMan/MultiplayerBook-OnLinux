#include<memory>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>


using namespace std;

class SocketAddress
{
    public:
	SocketAddress(uint32_t inAddress, uint16_t inPort){
	    GetAsSockAddrIn()->sin_family = AF_INET;
	    GetAsSockAddrIn()->sin_addr.s_addr = htonl(inAddress);
	    GetAsSockAddrIn()->sin_port = htons(inPort);
	}

	SocketAddress(const sockaddr& inSockAddr){
	    memcpy(&mSockAddr, &inSockAddr, sizeof(sockaddr));
	}

	size_t GetSize() const {return sizeof(sockaddr);}

    private:
	sockaddr mSockAddr;

	sockaddr_in* GetAsSockAddrIn(){
	    return reinterpret_cast<sockaddr_in*>(&mSockAddr);
	}

};

using SockertAddressPtr = shared_ptr<SocketAddress>;

int main()
{
    SocketAddress sa = SocketAddress(127001, 3000);
    return 0;
}
