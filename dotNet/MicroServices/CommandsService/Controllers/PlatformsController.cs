using Microsoft.AspNetCore.Mvc;

namespace CommandsService.Controllers
{
    [Route("api/c/[controller]")]
    [ApiController]
    public class PlatformsController : ControllerBase
    {
        public PlatformsController()
        {

        }

        public ActionResult TestInbourdConnection()
        {
            Console.WriteLine("--> TEST");

            return Ok(" TEST IS WORKINF");
        }
    }

}