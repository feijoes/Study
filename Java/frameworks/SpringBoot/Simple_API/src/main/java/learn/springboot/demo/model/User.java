package learn.springboot.demo.model;
import com.fasterxml.jackson.annotation.JsonProperty;
import org.springframework.lang.NonNull;

import java.util.UUID;
public class User {
    private final UUID id;
    @NonNull
    private final String name;

    public User(@JsonProperty("id")UUID id,@JsonProperty("name") String name){
        this.id = id;
        this.name = name;
    }
    public UUID getId(){
        return id;
    }
    public String getName(){
        return name;
    }
}
