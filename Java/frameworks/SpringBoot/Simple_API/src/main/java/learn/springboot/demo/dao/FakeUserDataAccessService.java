package learn.springboot.demo.dao;

import learn.springboot.demo.model.User;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Repository("fakeDao")
public class FakeUserDataAccessService implements UserDao {

    private static List<User> DB = new ArrayList<User>();

    @Override
    public int insertUser(UUID id, User user) {
        DB.add(new User(id,user.getName()));
        return 1;
    }

    @Override
    public Optional<User> selectUserById(UUID id) {
        return DB.stream().filter(u -> u.getId().equals(id)).findFirst();
    }

    @Override
    public List<User> selectAllUser(){
        return DB;
    }

    @Override
    public int deleteUserById(UUID id) {
        Optional<User> userMaybe= selectUserById(id);
        if (userMaybe.isEmpty()){
            return 0;
        }
        DB.remove(userMaybe.get());
        return 1;

    }

    @Override
    public int updateUserById(UUID id, User user) {
        return selectUserById(id).map(p->{
            int indexOfUserToUpdate = DB.indexOf(p);
            if (indexOfUserToUpdate >= 0){
                DB.set(indexOfUserToUpdate,new User(id,user.getName()));
                return 1;
            }
            return 0;
        }).orElse(0);
    }

}
