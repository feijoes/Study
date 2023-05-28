package api.schoolAPI.model;
import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Getter;
import lombok.NonNull;
import lombok.Setter;
import lombok.ToString;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;
import java.util.List;
import java.util.UUID;

@Getter
@Setter
@ToString
@Document(collection = "Courses")
public class Courses {
    @Id
    private String id;
    private String name;
    private List<String> activities;
    public Courses(@JsonProperty("name") String name,@JsonProperty("activities") List<String> activities){
        this.name = name;
        this.id = String.valueOf(UUID.randomUUID());
        this.activities = activities;
    }
}
