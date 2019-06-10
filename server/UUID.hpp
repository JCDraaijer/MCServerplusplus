//
// Created by jona on 2019-06-02.
//

#ifndef MCSERVER_UUID_HPP
#define MCSERVER_UUID_HPP


class UUID {
private:
    const unsigned long mostSignificant;
    const unsigned long leastSignificant;
public:
    UUID(long, long);
    bool equals(UUID);
};


#endif //MCSERVER_UUID_HPP
