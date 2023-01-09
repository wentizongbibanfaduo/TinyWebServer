#include "config.h"

Config::Config()
{
    //端口号,默认9006
    m_port = 9006;

    //日志写入方式，默认同步
    m_log_write = 0;

    //触发组合模式,默认listenfd LT + connfd LT
    m_trig_mode = 0;

    //listenfd触发模式，默认LT
    m_listen_trig_mode = 0;

    //connfd触发模式，默认LT
    m_conn_trig_mode = 0;

    //优雅关闭链接，默认不使用
    m_opt_linger = 0;

    //数据库连接池数量,默认8
    m_sql_nums = 8;

    //线程池内的线程数量,默认8
    m_thread_nums = 8;

    //关闭日志,默认不关闭
    m_close_log = 0;

    //并发模型,默认是proactor
    m_actor_model = 0;

    m_user = "root";
    m_password = "root";
    m_database_name = "yourdb";
}


void Config::select_trig_mode() {
    const int trig_mode = get_trig_mode();
    //LT + LT
    if (0 == trig_mode)
    {
        set_listen_trig_mode(0);
        set_conn_trig_mode(0);
    }
        //LT + ET
    else if (1 == trig_mode)
    {
        set_listen_trig_mode(0);
        set_conn_trig_mode(1);
    }
        //ET + LT
    else if (2 == trig_mode)
    {
        set_listen_trig_mode(1);
        set_conn_trig_mode(0);
    }
        //ET + ET
    else if (3 == trig_mode)
    {
        set_listen_trig_mode(1);
        set_conn_trig_mode(1);
    }
}

void Config::parse_arg(int argc, char* argv[])
{
    int opt;
    const char *str = "p:l:m:o:s:t:c:a:u:w:d:";
    while ((opt = getopt(argc, argv, str)) != -1)
    {
        switch (opt)
        {
            case 'p':
            {
                set_port(atoi(optarg));
                break;
            }
            case 'l':
            {
                set_log_write(atoi(optarg));
                break;
            }
            case 'm':
            {
                set_trig_mode(atoi(optarg));
                break;
            }
            case 'o':
            {
                set_opt_linger(atoi(optarg));
                break;
            }
            case 's':
            {
                set_sql_nums(atoi(optarg));
                break;
            }
            case 't':
            {
                set_thread_nums(atoi(optarg));
                break;
            }
            case 'c':
            {
                set_close_log(atoi(optarg));
                break;
            }
            case 'a':
            {
                set_actor_model(atoi(optarg));
                break;
            }
            case 'u':
            {
                set_user(optarg);
                break;
            }
            case 'w':
            {
                set_password(optarg);
                break;
            }
            case 'd':
            {
                set_database_name(optarg);
                break;
            }

            default:
                break;
        }
    }
    select_trig_mode();
}