#pragma once
#include <string>

namespace gflow {

enum class StatusCode {
    STATUS_OK                 = 1,

    STATUS_NETWORK_ERROR      = 2,
    STATUS_NOT_CONNECTED      = 3,
    STATUS_UNREACHABLE        = 4,
    STATUS_PARSE_ERROR        = 5,
    STATUS_REQUEST_TIMEOUT    = 6,
    STATUS_NOT_FOUND          = 7,
    STATUS_PERMISSION_DENIED  = 8,

    STATUS_ABORT              = 9,
    STATUS_OUT_OF_RANGE       = 10,

    STATUS_UNKNOW_ERROR       = 0x7fffffff
};


class Status {
public:
    Status() : code_(StatusCode::STATUS_OK)
    {
    }

    Status(StatusCode code) : code_(code)
    {
    }

    Status(StatusCode code, std::string msg)
        : code_(code), msg_(msg)
    {
    }

    bool ok() { return code_ == StatusCode::STATUS_OK; }
    std::string what() { return msg_; }
    std::string msg()  { return msg_; }

private:
    StatusCode code_;
    std::string msg_;

};




inline Status OkStatus() { return Status(); }
inline Status NetworkErrorStatus() { return Status(StatusCode::STATUS_NETWORK_ERROR); }
inline Status NotConnectedStatus() { return Status(StatusCode::STATUS_NOT_CONNECTED); }
inline Status UnreachableStatus()  { return Status(StatusCode::STATUS_UNREACHABLE);   }


} // namespace gflow

