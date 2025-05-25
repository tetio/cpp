#include "rotational_cipher.h"

namespace rotational_cipher
{

    string rotate(string text, unsigned int key)
    {
        string res;
        res.reserve(text.length());
        for (size_t i = 0; i < text.size(); i++)
        {
            int c = text[i];
            int ascii_gap = 0;
            if (c >= 97 && c <= 132)
            {
                ascii_gap = 97;
            }
            else if (c >= 65 && c < 97)
            {
                ascii_gap = 65;
            }
            if (ascii_gap > 0)
            {
                c = c - ascii_gap;
                c = (c + key) % 26 + ascii_gap;
            }
            res.push_back(c);
        }
        return res;
    }

} // namespace rotational_cipher
