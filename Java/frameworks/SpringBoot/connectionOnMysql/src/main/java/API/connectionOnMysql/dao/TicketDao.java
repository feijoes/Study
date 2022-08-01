package API.connectionOnMysql.dao;

import API.connectionOnMysql.model.Ticket;
import org.springframework.data.repository.CrudRepository;

public interface TicketDao extends CrudRepository<Ticket, Integer> {

}
