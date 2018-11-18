#ifndef HELP_H   //If not Define
#define HELP_H

#include <ctime>
#include <string>
#include <sstream>

namespace Help
{
    template <class T>
    std::string ToString(const T &); //convert string function

    struct DateTime // similar to public class in java can be access by other
    {
        DateTime()
        {
           time_t milliseconds;
            time (&milliseconds); //passing the data to this variable

            struct tm *info = localtime(&milliseconds);
            D = info->tm_mday;
            m = info->tm_mon + 1;   // plus 1 because we want it to start with january the default is zero
            y = 1900 + info->tm_year;
            M = info->tm_min;
            H = info->tm_hour;
            S = info->tm_sec;
        }

        DateTime(int D, int m, int y, int H, int M, int S) : D(D), m(m), y(y), H(H), M(M), S(S){}
        DateTime(int D, int m, int y) : D(D), m(m), y(y), H(0), M(0), S(0) {}

        DateTime Now () const // will only read but not will going to change anything
        {
            return DateTime();
        }
        int D, m, y, H, M, S;

        std::string GetDateString() const
        {
            return std::string( D < 10 ? "0" : "") + ToString(D) +
                   std::string( m < 10 ? ".0" : ".") + ToString(m) + "." + ToString(y);

                   // this will format it to DD.mm.Year
         }
         std::string GetTimeString(const std::string &sep = ":") const
         {
             return  std::string( H <10 ? "0" : "") + ToString(H) + sep +
                     std::string( M <10 ? "0" : "") + ToString(M) + sep +
                     std::string( S <10 ? sep : "") + ToString(S);

                     // format is HH:MM:SS
         }

          std::string GetDateTimeString(const std::string &sep = ":") const
          {
              return GetDateString() + "" + GetTimeString(sep);
          }

    };
template <class T>
std::string ToString(const T &e)
{
    std::ostringstream s;
    s << e;   // << is an Insertion operator
    return  s.str();

}

void WriteApplog( const std::string &s)
{
    std::ofstream file("Applog.txt", std::ios::app);
    file << "[" << Help::DateTime().GetDateTimeString() << "]" <<
    "\n" << s << std::endl << "\n";
    file.close();

    }
}               // not sure if this will cause an error


#endif // HELP_H
