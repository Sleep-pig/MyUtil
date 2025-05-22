#include <iostream>
#include <queue>
#include <memory>
#include<Design/SingleTon.h>
#include <MessageNode/MessageNode.h>
#include <thread>
#include <mutex>
#include <condition_variable>


std::ostream& operator<<(std::ostream& os, pjie::Logic_Node& node) {
	std::string typestr;
	char* buf = nullptr;
	switch (node.type_)
	{
	case pjie::LogicType::RECV_REQUEST:
		typestr = "RECV_REQUEST";
		buf = node.node_->Buffer();
		strcpy(buf, "recvvvvvv");
		break;
	case pjie::LogicType::SEND_RESPONSE:
		typestr = "SEND_RESPONSE";
		buf = node.node_->Buffer();
		strcpy(buf, "seddd");
		break;
	case pjie::LogicType::SEND_REQUEST:
		typestr = "SEND_REQUEST";
		buf = node.node_->Buffer();
		strcpy(buf, "sedd_");
		break;
	case pjie::LogicType::RECV_RESPONSE:
		typestr = "RECV_RESPONSE";
		buf = node.node_->Buffer();
		strcpy(buf, "recvvvvvv_");
		break;
	default:
		typestr = "UNKNOWN";
		break;
	}
	os << "type: " << typestr << " connect: " << node.connect_ << " node: " << node.node_->Buffer();
	return os;
}


class LogicSession :public pjie::Singleton<LogicSession> {
	friend class pjie::Singleton<LogicSession>;
public:

	void AddNode(std::shared_ptr<pjie::Logic_Node> node) {
        std::unique_lock<std::mutex> lock(mtx_);
		cv_.wait(lock, [this] {
			return que_.size() < 10;
			});
        que_.push(node);
        cv_.notify_one();
	}

	void ProcessNode() {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this] {
			return !que_.empty();
			});
		auto node = que_.front();
		que_.pop();
		std::cout<<"ProcessNode: "<<*(node.get())<<std::endl;
		cv_.notify_one();
    }

private:
	std::queue<std::shared_ptr<pjie::Logic_Node >> que_;
	std::mutex mtx_;
	std::condition_variable cv_;
};


void test1() {
	for (int i = 0; i < 15; i++) {
		std::shared_ptr<pjie::Recv_Node> node = std::make_shared<pjie::Recv_Node>(1024);
		std::shared_ptr<pjie::Logic_Node> logicnode = std::make_shared<pjie::Logic_Node>(std::string("recvrequest"), node);
		logicnode->SetType(pjie::LogicType::RECV_REQUEST);
        LogicSession::GetInstance()->AddNode(logicnode);
	}
}

void test2() {
	for (int i = 0; i < 10; i++) {
		char buf[1024] = "1111111";
		std::shared_ptr<pjie::Send_Node> node = std::make_shared<pjie::Send_Node>(buf,strlen(buf));
		std::shared_ptr<pjie::Logic_Node> logicnode = std::make_shared<pjie::Logic_Node>(std::string("sendrequest"), node);
		logicnode->SetType(pjie::LogicType::SEND_REQUEST);
		LogicSession::GetInstance()->AddNode(logicnode);
	}
}


int main() {
	std::thread t3([] {
		while (true) {
			LogicSession::GetInstance()->ProcessNode();
		}
		});
	std::thread t1(&test1);
	std::thread t2(&test2);
	t1.join();
    t2.join();
    t3.join();
}


