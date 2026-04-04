#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <iostream>

class TextFileReader {
public:
    static std::vector<std::wstring> ReadAllLines(const std::string& path) {
        std::string raw = readFile(path);
        std::wstring text = decode(raw);
        return splitLines(text);
    }

private:
    // ========================
    // 1️ 读取原始字节
    // ========================
    static std::string readFile(const std::string& path) {
        std::ifstream file(path, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Cannot open file");
        }

        return std::string(
            (std::istreambuf_iterator<char>(file)),
            std::istreambuf_iterator<char>()
        );
    }

    // ========================
    // 2️ 编码识别 + 转换
    // ========================
    static std::wstring decode(const std::string& raw) {
        // UTF-8 BOM: EF BB BF
        if (raw.size() >= 3 &&
            (unsigned char)raw[0] == 0xEF &&
            (unsigned char)raw[1] == 0xBB &&
            (unsigned char)raw[2] == 0xBF) {

            return utf8ToWstring(raw.substr(3));
        }

        // 尝试判断是否是 UTF-8（简单检测）
        if (isValidUTF8(raw)) {
            return utf8ToWstring(raw);
        }

        // 否则当作 GBK
        return gbkToWstring(raw);
    }

    // ========================
    // UTF-8 → wstring
    // ========================
    static std::wstring utf8ToWstring(const std::string& str) {
        int size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
        std::wstring result(size - 1, 0); // 去掉末尾 \0
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &result[0], size);
        return result;
    }

    // ========================
    // GBK → wstring
    // ========================
    static std::wstring gbkToWstring(const std::string& str) {
        int size = MultiByteToWideChar(936, 0, str.c_str(), -1, NULL, 0);
        std::wstring result(size - 1, 0);
        MultiByteToWideChar(936, 0, str.c_str(), -1, &result[0], size);
        return result;
    }

    // ========================
    // UTF-8 合法性检测（简单版）
    // ========================
    static bool isValidUTF8(const std::string& str) {
        int i = 0;
        int len = str.size();

        while (i < len) {
            unsigned char c = str[i];

            if (c <= 0x7F) {
                i++;
            }
            else if ((c >> 5) == 0x6) { // 110xxxxx
                if (i + 1 >= len) return false;
                if ((str[i + 1] >> 6) != 0x2) return false;
                i += 2;
            }
            else if ((c >> 4) == 0xE) { // 1110xxxx
                if (i + 2 >= len) return false;
                if ((str[i + 1] >> 6) != 0x2 ||
                    (str[i + 2] >> 6) != 0x2) return false;
                i += 3;
            }
            else if ((c >> 3) == 0x1E) { // 11110xxx
                if (i + 3 >= len) return false;
                if ((str[i + 1] >> 6) != 0x2 ||
                    (str[i + 2] >> 6) != 0x2 ||
                    (str[i + 3] >> 6) != 0x2) return false;
                i += 4;
            }
            else {
                return false;
            }
        }

        return true;
    }

    // ========================
    // 3️ 按行拆分
    // ========================
    static std::vector<std::wstring> splitLines(const std::wstring& text) {
        std::vector<std::wstring> lines;
        std::wstring line;

        for (wchar_t ch : text) {
            if (ch == L'\n') {
                if (!line.empty() && line.back() == L'\r') {
                    line.pop_back(); // 处理 \r\n
                }
                std::wcout << "LINE: " << line << std::endl;
                lines.push_back(line);
                line.clear();
            }
            else {
                line += ch;
            }
        }

        if (!line.empty()) {
            lines.push_back(line);
        }

        return lines;
    }
};