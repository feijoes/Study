using System.Collections.Generic;
using PlatformService.Models;
namespace PlatformService.Data
{
    public interface IPlatformRepo
    {
        bool SaveChanges();

        IEnumerable<Platform> GetPlatforms();

        Platform GetPlatformById(int id);

        void CreatePlatform(Platform plat);
    }
}