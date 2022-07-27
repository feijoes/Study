package learn.springboot.demo.dao;

import learn.springboot.demo.model.User;

import java.util.UUID;

public interface UserDao {


    int insertUser(UUID id, User user);

    default int insertUser(User user){
        UUID id = UUID.randomUUID();
        return insertUser(id,user);
    }
}
