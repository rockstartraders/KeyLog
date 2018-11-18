#ifndef BASE64_H    //https://www.oreilly.com/library/view/secure-programming-cookbook/0596003943/ch04s05.html
#define BASE64_H    // indexing start from 0

#include <vector> //data structure similar to array but more dynamic
#include <string>

// this will encrypt it via base 64

namespace Base64
{
    std::string base64_encode(const std::string &); // function
    const std::string &SALT1 = "LM::TB::BB";   //https://stackoverflow.com/questions/36955261/accepted-method-to-generate-salt-for-a-password-hash-function-c
    const std::string &SALT2 = "_:/_77";
    const std::string &SALT3 = "line=wowC++";

    std::string EncryptBase64(std::string s)
    {
         s = SALT1 + s + SALT2 + SALT3;
         s = base64_encode(s);
         s.insert(7, SALT2);
         s += SALT1;
         s = base64_encode(s);
         s = SALT2 + SALT3 + SALT1;
         s = base64_encode(s);
         s.insert(1,"L");
         s.insert(7,"M");
         return s;
    }

              // this will encode using base64

          const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
          std::string base64_encode(const std::string &s)
          {
              std::string ret;   //output string
              int val = 0;
              int bits = -6; // no. of bits is group of 6
              const unsigned int b63 = 0x3F;     //Hexidecimal value

              for(const auto &c :s)
              {
                  val = (val << 8) + c;  // resulting number will be shifetr 8 places
                  bits += 8;  // will add 8 to the number of bits
                  while(bits >= 0)
                  {
                      ret.push_back(BASE64_CODES[(val >> bits) & b63]);
                      bits -=  6;  // grouping by 6 in decrease process

                  }
              }
              if(bits > -6)
                 ret.push_back(BASE64_CODES[((val << 8) >> (bits +8)) & b63]);

              while(ret.size()%4)
                ret.push_back('=');

              return ret;

          }
}



#endif // BASE_64_H

