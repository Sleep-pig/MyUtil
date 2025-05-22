#pragma once
#include <string>
#include <memory>
namespace pjie {


	enum class LogicType {
		RECV_REQUEST,
        SEND_RESPONSE,
        SEND_REQUEST,
        RECV_RESPONSE,
	};

class MessageNode {
public:
	MessageNode() = default;
	MessageNode(size_t size) :totalsize_(size) {
		buffer_ = new char[size + 1];
		buffer_[size] = '\0';
	}
    ~MessageNode() {
		if(buffer_) delete[] buffer_;
	}

	void Clear() {
		memset(buffer_, 0, totalsize_ + 1);
        cursize_ = 0;
	}
	size_t Size() { return cursize_; }
	char* Buffer() {return buffer_;}

public:
	char* buffer_;
	size_t totalsize_;
	size_t cursize_;

};

class Recv_Node : public MessageNode {
public:
    Recv_Node(size_t size) : MessageNode(size)
    {
		cursize_ = 0;
    }
};



class Send_Node : public MessageNode {
public:

	Send_Node(const char* data, size_t size) : MessageNode(size) {
		cursize_ = size;
        memcpy(buffer_, data, size);
	}
};

class Logic_Node {
public:
	Logic_Node(std::string connect,std::shared_ptr<MessageNode> node)
		:connect_(connect), node_(node)
	{
	}
	void SetType(LogicType type) {
		type_ = type;
	}

    LogicType GetType() {
		return type_;
	}

	

	std::string connect_;
    std::shared_ptr<MessageNode> node_;
    LogicType type_;

};




}