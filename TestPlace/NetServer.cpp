#include<iostream>
#include<locale>

#include"XVRToolbox.h"

enum class CustomMsgTypes : uint32_t
{
	ServerAccept,
	ServerDeny,
	ServerPing,
	MessageAll,
	ServerMessage,
};

class CustomServer : public xvr::net::server_interface<CustomMsgTypes>
{
public:
	CustomServer(uint16_t nPort) : xvr::net::server_interface<CustomMsgTypes>(nPort)
	{

	}

protected:
	virtual bool OnClientConnect(std::shared_ptr<xvr::net::connection<CustomMsgTypes>> client)
	{
		xvr::net::message<CustomMsgTypes> msg;
		msg.header.id = CustomMsgTypes::ServerAccept;
		client->Send(msg);

		return true;
	}

	virtual void OnClientDisconnect(std::shared_ptr<xvr::net::connection<CustomMsgTypes>> client)
	{
		std::cout << "[SERVER] Removing client [" << client->GetID() << "]\n";
	}

	virtual void OnMessage(std::shared_ptr<xvr::net::connection<CustomMsgTypes>> client, xvr::net::message<CustomMsgTypes>& msg)
	{
		switch (msg.header.id)
		{
		case CustomMsgTypes::ServerPing:
		{
			std::cout << "[" << client->GetID() << "]: Server Ping\n";

			// Simply bounce message back to client
			client->Send(msg);
		}
		break;

		case CustomMsgTypes::MessageAll:
		{
			std::cout << "[" << client->GetID() << "]: Message All\n";
			xvr::net::message < CustomMsgTypes> msg;
			msg.header.id = CustomMsgTypes::ServerMessage;
			msg << client->GetID();
			MessageAllClients(msg, client);

		}
		break;
		}
	}
};

int main()
{
	CustomServer server(5555);
	server.Start();

	while (1)
	{
		server.Update(-1,true);
	}
	return 0;
}