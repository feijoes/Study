using Microsoft.AspNetCore.Mvc;
using AutoMapper;
using PlatformService.Data;
using PlatformService.Dtos;
using PlatformService.Models;
namespace PlatformService.Controllers
{
    [Route("api/[controller]")]
    [ApiController ]
    public class PlatformsController : ControllerBase
    {
        private readonly IPlatformRepo _repository;
        private readonly IMapper _mapper;
        public PlatformsController(IPlatformRepo repo, IMapper mapper)
        {
            _repository = repo;
            _mapper = mapper;
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
        public ActionResult<PlatformReadDto> CreatePlatform(PlatformCreateDto plat)
        {
            var platformModel = _mapper.Map<Platform>(plat);
            _repository.CreatePlatform(platformModel);
            _repository.SaveChanges();
            
            var platformReadDto = _mapper.Map<PlatformReadDto>(platformModel);
            return CreatedAtRoute(nameof(GetPlatformById), new {Id=platformReadDto.Id}, platformReadDto);
        }
    }
}