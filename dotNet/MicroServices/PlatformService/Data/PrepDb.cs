using PlatformService.Models;
using Microsoft.EntityFrameworkCore;
namespace PlatformService.Data
{
    public static class PrepDb
    {
        private static void SeedData(AppDbContext context,bool isProd)
        {
            if(isProd)
            {
                try
                {
                    context.Database.Migrate();
                }
                catch (System.Exception ex)
                {
                    
                    Console.WriteLine($"--> Could not run migrations: {ex.Message}");
                }
                
            }
            if(!context.Platforms.Any())
            {
                Console.WriteLine("Seeding Data...");
                context.Platforms.AddRange(
                    new Platform(){Name="Dot Net", Publisher="Microsoft",Cost="Free"},
                    new Platform(){Name="Test1Name", Publisher="Test1Publisher",Cost="Free"},
                    new Platform(){Name="Test2Name", Publisher="Test2Publisher",Cost="Free"}
                );

                context.SaveChanges();
            }
            else
            {
                Console.WriteLine("Already have data");
            }
        }
        public static void PrepPopulation(IApplicationBuilder app, bool isProd)
        {
            using( var serviceScope = app.ApplicationServices.CreateScope())
            {
                SeedData(serviceScope.ServiceProvider.GetService<AppDbContext>(), isProd);
            }
        }
            
    }
}
