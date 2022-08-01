package API.connectionOnMysql.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import API.connectionOnMysql.dao.TicketDao;
import API.connectionOnMysql.model.Ticket;


@RestController
public class TicketController {
    @Autowired
    private TicketDao dao;

    @PostMapping
    public String bookTicket(@RequestBody Ticket ticket) {
        dao.save(ticket);
        return "ticket booked ";
    }

    @GetMapping
    public List<Ticket> getTickets() {
        return (List<Ticket>) dao.findAll();
    }

}