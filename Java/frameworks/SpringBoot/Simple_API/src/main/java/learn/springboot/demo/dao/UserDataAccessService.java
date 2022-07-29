package learn.springboot.demo.dao;

import learn.springboot.demo.model.User;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Repository("postgress")
public class UserDataAccessService implements UserDao{
    @Override
    public int insertUser(UUID id, User user) {
        return 0;
    }

    @Override
    public Optional<User> selectUserById(UUID id) {
        return Optional.empty();
    }

    @Override
    public List<User> selectAllUser() {
        return null;
    }

    @Override
    public int deleteUserById(UUID id) {
        return 0;
    }

    @Override
    public int updateUserById(UUID id, User user) {
        return 0;
    }
}
