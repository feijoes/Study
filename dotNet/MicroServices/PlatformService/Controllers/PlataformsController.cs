using Microsoft.AspNetCore.Mvc;
using AutoMapper;
using PlatformService.Data;
using PlatformService.Dtos;
using PlatformService.Models;
using PlatformService.SyncDataService.Http;
namespace PlatformService.Controllers
{
    [Route("api/[controller]")]
    [ApiController ]
    public class PlatformsController : ControllerBase
    {
        private readonly IPlatformRepo _repository;
        private readonly IMapper _mapper;

        private readonly ICommandDataClient _commandDataClient;
        public PlatformsController(IPlatformRepo repo, IMapper mapper,ICommandDataClient commandDataClient)
        {
            _repository = repo;
            _mapper = mapper;
            _commandDataClient = commandDataClient;
        }
        [HttpGet]
        public ActionResult<IEnumerable<PlatformRepo>> GetPlatforms()
        {
            Console.WriteLine("Getting Platforms");
            return Ok(_mapper.Map<IEnumerable<PlatformReadDto>>(_repository.GetAllPlatforms()));
        }
        [HttpGet("{id}", Name = "GetPlatformById")]
        public ActionResult<PlatformReadDto> GetPlatformById(int id)
        {
           var platformItem = _repository.GetPlatformById(id);
           if (platformItem != null)
            {
                return Ok(_mapper.Map<PlatformReadDto>(platformItem));
            }
           return NotFound();
        }
        [HttpPost]
        public async Task<ActionResult<PlatformReadDto>> CreatePlatform(PlatformCreateDto plat)
        {
            var platformModel = _mapper.Map<Platform>(plat);
            _repository.CreatePlatform(platformModel);
            _repository.SaveChanges();
            
            var platformReadDto = _mapper.Map<PlatformReadDto>(platformModel);
            try
            {
                await _commandDataClient.SendPlatformToCommand(platformReadDto);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"--> Cound not send synchrounsly: {ex.Message}");
            }
            return CreatedAtRoute(nameof(GetPlatformById), new {Id=platformReadDto.Id}, platformReadDto);
        }
    }
}