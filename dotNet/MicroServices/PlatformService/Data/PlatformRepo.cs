using PlatformService.Models;

namespace PlatformService.Data
{
    public class PlatformRepo : IPlatformRepo
    {
        
        private readonly AppDbContext _context;
        public PlatformRepo(AppDbContext context)
        {
            _context = context;
        }
        void IPlatformRepo.CreatePlatform(Platform plat)
        {
           if(plat == null)
           {
            throw new ArgumentNullException(nameof(plat));
           }
           _context.Platforms.Add(plat);
        }

        Platform IPlatformRepo.GetPlatformById(int id)
        {
            return _context.Platforms.FirstOrDefault(p => p.Id == id) ;
        }

        IEnumerable<Platform> IPlatformRepo.GetAllPlatforms()
        {
            return _context.Platforms.ToList();
        }

        bool IPlatformRepo.SaveChanges()
        {
            return (_context.SaveChanges() >= 0);
        }
    }
}