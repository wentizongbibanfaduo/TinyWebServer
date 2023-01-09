#ifndef CONFIG_H
#define CONFIG_H

#include <unistd.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Config
{
public:
    Config();
    ~Config(){};

    void parse_arg(int argc, char*argv[]);

    void set_port(const int value);
    void set_log_write(const int value);
    void set_trig_mode(const int value);
    void set_listen_trig_mode(const int value);
    void set_conn_trig_mode(const int value);
    void set_opt_linger(const int value);
    void set_sql_nums(const int value);
    void set_thread_nums(const int value);
    void set_close_log(const int value);
    void set_actor_model(const int value);
    void set_user(const std::string& value);
    void set_password(const std::string& value);
    void set_database_name(const std::string& value);

    int get_port() const;
    int get_log_write() const;
    int get_trig_mode() const;
    int get_listen_trig_mode() const;
    int get_conn_trig_mode() const;
    int get_opt_linger() const;
    int get_sql_nums() const;
    int get_thread_nums() const;
    int get_close_log() const;
    int get_actor_model() const;
    const std::string& get_user() const;
    const std::string& get_password() const;
    const std::string& get_database_name() const;

private:
    //端口号
    int m_port;

    //日志写入方式
    int m_log_write;

    //触发组合模式
    int m_trig_mode;

    //listenfd触发模式
    int m_listen_trig_mode;

    //connfd触发模式
    int m_conn_trig_mode;

    //优雅关闭链接
    int m_opt_linger;

    //数据库连接池数量
    int m_sql_nums;

    //线程池内的线程数量
    int m_thread_nums;

    //是否关闭日志
    int m_close_log;

    //并发模型选择
    int m_actor_model;

    //登陆数据库用户名
    std::string m_user;

    //登陆数据库密码         
    std::string m_password;

    //使用数据库名    
    std::string m_database_name; 
};

inline void Config::set_port(const int value)
{
    m_port = value;
}

inline void Config::set_log_write(const int value)
{
    m_log_write = value;
}

inline void Config::set_trig_mode(const int value)
{
    m_trig_mode = value;
}

inline void Config::set_listen_trig_mode(const int value)
{
    m_listen_trig_mode = value;
}

inline void Config::set_conn_trig_mode(const int value)
{
    m_conn_trig_mode = value;
}

inline void Config::set_opt_linger(const int value)
{
    m_opt_linger = value;
}

inline void Config::set_sql_nums(const int value)
{
    m_sql_nums = value;
}

inline void Config::set_thread_nums(const int value)
{
    m_thread_nums = value;
}

inline void Config::set_close_log(const int value)
{
    m_close_log = value;
}

inline void Config::set_actor_model(const int value)
{
    m_actor_model = value;
}

inline void Config::set_user(const std::string& value) {
    m_user = value;
}

inline void Config::set_password(const std::string& value)
{
    m_password = value;
}

inline void Config::set_database_name(const std::string& value)
{
    m_database_name = value;
}

inline int Config::get_port() const {
    return m_port;
}

inline int Config::get_log_write() const {
    return m_log_write;
}

inline int Config::get_trig_mode() const {
    return m_trig_mode;
}

inline int Config::get_listen_trig_mode() const {
    return m_listen_trig_mode;
}

inline int Config::get_conn_trig_mode() const {
    return m_conn_trig_mode;
}

inline int Config::get_opt_linger() const {
    return m_opt_linger;
}

inline int Config::get_sql_nums() const {
    return m_sql_nums;
}

inline int Config::get_thread_nums() const {
    return m_thread_nums;
}

inline int Config::get_close_log() const {
    return m_close_log;
}

inline int Config::get_actor_model() const {
    return m_actor_model;
}

inline const std::string& Config::get_user() const {
    return m_user;
}

inline const std::string& Config::get_password() const {
    return m_password;
}

inline const std::string& Config::get_database_name() const {
    return m_database_name;
}
#endif